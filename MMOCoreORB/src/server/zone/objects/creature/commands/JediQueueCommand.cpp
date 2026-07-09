#include "JediQueueCommand.h"
#include "server/zone/objects/creature/buffs/Buff.h"
#include "server/zone/objects/creature/CreatureObject.h"
#include "server/zone/managers/visibility/VisibilityManager.h"
#include "server/zone/objects/creature/buffs/SingleUseBuff.h"
#include "server/zone/objects/player/PlayerObject.h"
#include "server/zone/managers/frs/FrsManager.h"

JediQueueCommand::JediQueueCommand(const String& name, ZoneProcessServer* server) : QueueCommand(name, server) {
	forceCost = 0;
	duration = 0;
	animationCRC = 0;
	clientEffect = "";
	buffClass = BASE_BUFF;
	speedMod = 0;
	visMod = 10;
	buffCRC = 0;
	frsLightForceCostModifier = 0;
	frsDarkExtraForceCostModifier = 0;
	frsLightExtraForceCostModifier = 0;
	frsDarkForceCostModifier = 0;
	frsLightBuffModifier = 0;
	frsDarkBuffModifier = 0;
	frsLightForcePowerModifier = 0;
	frsDarkForcePowerModifier = 0;
}

int JediQueueCommand::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	return SUCCESS;
}

bool JediQueueCommand::isJediQueueCommand() const {
	return true;
}

int JediQueueCommand::doJediSelfBuffCommand(CreatureObject* creature) const {
	// first and foremost, we need to toggle this buff off if we already have it
	if (creature->hasBuff(buffCRC)) {
		creature->removeBuff(buffCRC);
		return SUCCESS;
	}

	// Do checks first.
	int res = doCommonJediSelfChecks(creature);

	if (res != SUCCESS)
		return res;

	return doBuff(creature);
}

int JediQueueCommand::doBuff(CreatureObject* creature) const {
	ManagedReference<Buff*> buff = createJediSelfBuff(creature);

	// Return if buff is NOT valid.
	if (buff == nullptr)
		return GENERALERROR;

	Locker locker(buff);

	// Add buff.
	creature->addBuff(buff);

	// Force Cost.
	doForceCost(creature);

	// Client Effect.
	if (!clientEffect.isEmpty()) {
		creature->playEffect(clientEffect, "");
	}

	// Return.
	return SUCCESS;
}

int JediQueueCommand::doJediForceCostCheck(CreatureObject* creature) const {
	// Check for Force Cost..
	ManagedReference<PlayerObject*> playerObject = creature->getPlayerObject();

	if (playerObject && playerObject->getForcePower() < getFrsModifiedForceCost(creature)) {
		creature->sendSystemMessage("@jedi_spam:no_force_power"); //"You do not have enough Force Power to peform that action.
		return GENERALERROR;
	}

	return SUCCESS;
}

int JediQueueCommand::doCommonJediSelfChecks(CreatureObject* creature) const {
	int res = doCommonMedicalCommandChecks(creature);

	if (res != SUCCESS)
		return res;

	if (isWearingArmor(creature))
		return NOJEDIARMOR;

	for (int i = 0; i < blockingCRCs.size(); ++i) {
		if (creature->hasBuff(blockingCRCs.get(i))) {
			return NOSTACKJEDIBUFF;
		}
	}

	res = doJediForceCostCheck(creature);
	return res;
}

ManagedReference<Buff*> JediQueueCommand::createJediSelfBuff(CreatureObject* creature) const {
	for (int i = 0; i < overrideableCRCs.size(); ++i) {
		int buff = overrideableCRCs.get(i);
		if (creature->hasBuff(buff)) {
			creature->removeBuff(buff);
		}
	}

	// Create buff object.
	ManagedReference<Buff*> buff = nullptr;

	if (buffClass == BASE_BUFF || singleUseEventTypes.size() == 0) {
		buff = new Buff(creature, buffCRC, duration, BuffType::JEDI);
	} else if (buffClass == SINGLE_USE_BUFF) {
		;
		SingleUseBuff* suBuff = new SingleUseBuff(creature, buffCRC, duration, BuffType::JEDI, getNameCRC());

		buff = suBuff;

		// Otherwise the compiler complains we're modifying member variables in a "const" function
		Vector<uint32> singleUseTypesCopy = singleUseEventTypes;

		Locker blocker(suBuff);
		suBuff->init(&singleUseTypesCopy);

	} else {
		error("Unknown buff type");
		return nullptr;
	}

	Locker locker(buff);

	if (speedMod > 0) {
		buff->setSpeedMultiplierMod(speedMod);
		buff->setAccelerationMultiplierMod(speedMod);
	}

	StringIdChatParameter start("jedi_spam", "apply_" + name);
	StringIdChatParameter end("jedi_spam", "remove_" + name);

	buff->setStartMessage(start);
	buff->setEndMessage(end);

	for (int i = 0; i < skillMods.size(); ++i) {
		int modValue = skillMods.elementAt(i).getValue();
		int frsModifiedValue = getFrsModifiedBuffValue(creature, modValue);
		buff->setSkillModifier(skillMods.elementAt(i).getKey(), frsModifiedValue);
	}

	return buff;
}

int JediQueueCommand::getFrsModifiedBuffValue(CreatureObject* player, int amount) const {
	PlayerObject* ghost = player->getPlayerObject();

	if (ghost == nullptr)
		return amount;

	Locker locker(player);

	FrsData* playerData = ghost->getFrsData();
	short councilType = playerData->getCouncilType();

	locker.release();

	float buffModifier = 0;
	int controlModifier = 0;

	if (councilType == FrsManager::COUNCIL_LIGHT) {
		controlModifier = player->getSkillMod("force_control_light");
		buffModifier = frsLightBuffModifier;
	} else if (councilType == FrsManager::COUNCIL_DARK) {
		controlModifier = player->getSkillMod("force_control_dark");
		buffModifier = frsDarkBuffModifier;
	}

	if (controlModifier == 0 || buffModifier == 0)
		return amount;

	return amount + (int)((controlModifier * buffModifier) + 0.5f);
}

int JediQueueCommand::getFrsModifiedForceCost(CreatureObject* creature) const {
	ManagedReference<PlayerObject*> ghost = creature->getPlayerObject();

	if (ghost == nullptr)
		return forceCost;

	Locker locker(creature);

	FrsData* playerData = ghost->getFrsData();
	int councilType = playerData->getCouncilType();

	locker.release();

	int manipulationMod = 0;
	float frsModifier = 0;

	if (councilType == FrsManager::COUNCIL_LIGHT) {
		manipulationMod = creature->getSkillMod("force_manipulation_light");
		frsModifier = frsLightForceCostModifier;
	} else if (councilType == FrsManager::COUNCIL_DARK) {
		manipulationMod = creature->getSkillMod("force_manipulation_dark");
		frsModifier = frsDarkForceCostModifier;
	}

	if (manipulationMod == 0 || frsModifier == 0)
		return forceCost;

	return forceCost + (int)((manipulationMod * frsModifier) + .5);
}

float JediQueueCommand::getFrsModifiedExtraForceCost(CreatureObject* creature, float val) const {
	ManagedReference<PlayerObject*> ghost = creature->getPlayerObject();

	if (ghost == nullptr)
		return val;

	Locker locker(creature);

	FrsData* playerData = ghost->getFrsData();
	int councilType = playerData->getCouncilType();

	locker.release();

	int manipulationMod = 0;
	float frsModifier = 0;

	if (councilType == FrsManager::COUNCIL_LIGHT) {
		manipulationMod = creature->getSkillMod("force_manipulation_light");
		frsModifier = frsLightExtraForceCostModifier;
	} else if (councilType == FrsManager::COUNCIL_DARK) {
		manipulationMod = creature->getSkillMod("force_manipulation_dark");
		frsModifier = frsDarkExtraForceCostModifier;
	}

	if (manipulationMod == 0 || frsModifier == 0)
		return val;

	return val + ((float)manipulationMod * frsModifier);
}

void JediQueueCommand::doForceCost(CreatureObject* creature) const {
	// Force Cost.
	ManagedReference<PlayerObject*> playerObject = creature->getPlayerObject();
	playerObject->setForcePower(playerObject->getForcePower() - getFrsModifiedForceCost(creature));
	VisibilityManager::instance()->increaseVisibility(creature, visMod);
}

void JediQueueCommand::setForceCost(int fc) {
	forceCost = fc;
}

void JediQueueCommand::setDuration(int dur) {
	duration = dur;
}

void JediQueueCommand::setAnimationCRC(uint32 crc) {
	animationCRC = crc;
}

void JediQueueCommand::setClientEffect(String ce) {
	clientEffect = ce;
}

void JediQueueCommand::setSpeedMod(float sm) {
	speedMod = sm;
}

void JediQueueCommand::setBuffClass(int bt) {
	buffClass = bt;
}

void JediQueueCommand::setVisMod(int vm) {
	visMod = vm;
}

int JediQueueCommand::getVisMod() const {
	return visMod;
}

void JediQueueCommand::setFrsLightForceCostModifier(float val) {
	frsLightForceCostModifier = val;
}
void JediQueueCommand::setFrsDarkForceCostModifier(float val) {
	frsDarkForceCostModifier = val;
}
void JediQueueCommand::setFrsDarkExtraForceCostModifier(float val) {
	frsDarkExtraForceCostModifier = val;
}
void JediQueueCommand::setFrsLightExtraForceCostModifier(float val) {
	frsLightExtraForceCostModifier = val;
}
void JediQueueCommand::setFrsLightBuffModifier(float val) {
	frsLightBuffModifier = val;
}
void JediQueueCommand::setFrsDarkBuffModifier(float val) {
	frsDarkBuffModifier = val;
}
void JediQueueCommand::setFrsLightForcePowerModifier(float val) {
	frsLightForcePowerModifier = val;
}
void JediQueueCommand::setFrsDarkForcePowerModifier(float val) {
	frsDarkForcePowerModifier = val;
}