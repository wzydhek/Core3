/*
 * QueueCommand.cpp
 *
 *  Created on: 22/05/2010
 *      Author: victor
 */

#include "QueueCommand.h"
#include "server/zone/objects/creature/CreatureObject.h"
#include "server/zone/objects/building/BuildingObject.h"
#include "server/zone/objects/player/PlayerObject.h"
#include "server/zone/objects/player/FactionStatus.h"
#include "server/zone/objects/tangible/weapon/WeaponObject.h"
#include "server/zone/managers/combat/CombatManager.h"
#include "server/zone/managers/frs/FrsManager.h"

QueueCommand::QueueCommand(const String& skillname, ZoneProcessServer* serv) : Logger() {
	server = serv;

	name = skillname;
	nameCRC = skillname.hashCode();

	maxRangeToTarget = 0;

	commandGroup = 0;

	stateMask = 0;
	targetType = 0;
	disabled = false;
	addToQueue = false;
	admin = false;

	defaultTime = 0.f;
	cooldown = 0;
	defaultPriority = NORMAL;

	setLogging(false);
	setGlobalLogging(true);
	setLoggingName("QueueCommand " + skillname);
}

/*
 * Sets the invalid locomotion for this command.
 * Parses the string from LUA's. Format: "4,12,13,"
 */
void QueueCommand::setInvalidLocomotions(const String& lStr) {
	StringTokenizer tokenizer(lStr);
	tokenizer.setDelimeter(",");

	String token = "";
	while (tokenizer.hasMoreTokens()) {
		tokenizer.getStringToken(token);

		if(!token.isEmpty())
			invalidLocomotion.add(Integer::valueOf(token));
	}
}


/*
 * Checks each invalid locomotion with the player's current locomotion
 */
bool QueueCommand::checkInvalidLocomotions(CreatureObject* creature) const {
	for (int i = 0; i < invalidLocomotion.size(); ++i) {
		if (invalidLocomotion.get(i) == creature->getLocomotion())
			return false;
	}

	return true;
}

/*
*	Checks cell access for the player creature if the target is in a cell
*/
bool QueueCommand::playerEntryCheck(CreatureObject* creature, TangibleObject* target) const {
	if (creature == nullptr || target == nullptr) {
		return false;
	}

	uint64 creoParentID = creature->getParentID();
	uint64 tarParentID = target->getParentID();

	if (!creature->isPlayerCreature() || tarParentID == 0) {
		return true;
	}

	if (creoParentID != tarParentID) {
		Reference<CellObject*> targetCell = target->getParent().get().castTo<CellObject*>();

		if (targetCell != nullptr) {
			ManagedReference<SceneObject*> parentSceneObject = targetCell->getParent().get();

			if (parentSceneObject != nullptr) {
				BuildingObject* buildingObject = parentSceneObject->asBuildingObject();

				if (buildingObject != nullptr && !buildingObject->isAllowedEntry(creature)) {
					return false;
				}
			}

			const ContainerPermissions* perms = targetCell->getContainerPermissions();

			// This portion of the check is specific for locked dungeons doors since they do not inherit perms from parent
			if (!perms->hasInheritPermissionsFromParent() && (creature->getRootParent() == target->getRootParent())) {
				if (!targetCell->checkContainerPermission(creature, ContainerPermissions::WALKIN)) {
					return false;
				}
			}
		}
	}
	return true;
}

void QueueCommand::onStateFail(CreatureObject* creature, uint32 actioncntr) const {
	if (!addToQueue)
		return;

	uint64 states = stateMask & creature->getStateBitmask();

	uint64 state = 1;
	int num = 0;

	while (num < 34) {
		if (states & state) {

			creature->clearQueueAction(actioncntr, 0, 5, num);
			return;

		}

		state *= 2;
		++num;
	}

	creature->error("unknown invalid state in onStateFail");
}

void QueueCommand::onLocomotionFail(CreatureObject* creature, uint32 actioncntr) const {
	if (!checkInvalidLocomotions(creature))
		creature->clearQueueAction(actioncntr, 0, 1, creature->getLocomotion());
}

/*
 * Unsuccessful command completion alerts the player of the invalid state
 */
void QueueCommand::onFail(uint32 actioncntr, CreatureObject* creature, uint32 errorNumber) const {
	StringIdChatParameter prm;
	switch (errorNumber) {
	case INVALIDSYNTAX:
		creature->sendSystemMessage(getSyntax());
		if (addToQueue)
			creature->clearQueueAction(actioncntr);
		break;
	case INVALIDSTATE:
		onStateFail(creature, actioncntr);
		break;
	case INVALIDLOCOMOTION:
		onLocomotionFail(creature, actioncntr);
		break;
	case INVALIDTARGET:
		if (addToQueue)
			creature->clearQueueAction(actioncntr, 0, 3, 0);
		break;
	case INVALIDWEAPON: { // this only gets returned from combat commands
		ManagedReference<WeaponObject*> weapon = creature->getWeapon();
		int attackType = -1;

		if (weapon != nullptr) {
			attackType = weapon->getAttackType();
		}

		switch (attackType) {
		case SharedWeaponObjectTemplate::RANGEDATTACK:
			creature->sendSystemMessage("@cbt_spam:no_attack_ranged_single");
			break;
		case SharedWeaponObjectTemplate::MELEEATTACK:
			creature->sendSystemMessage("@cbt_spam:no_attack_melee_single");
			break;
		default:
			creature->sendSystemMessage("@cbt_spam:no_attack_wrong_weapon"); // Can't be done with this weapon
			break;
		}

		if (addToQueue)
			creature->clearQueueAction(actioncntr);
		break;
	}
	case TOOFAR:
		if (addToQueue)
			creature->clearQueueAction(actioncntr, 0, 4, 0);
		break;

	case NOJEDIARMOR:
		creature->sendSystemMessage("@jedi_spam:not_with_armor"); // You cannot use Force powers or lightsaber abilities while wearing armor.
		if (addToQueue)
			creature->clearQueueAction(actioncntr);

		break;

	case NOSTACKJEDIBUFF:
		creature->sendSystemMessage("@jedi_spam:force_buff_present"); // You are already have a similar Force enhancement active.
		if (addToQueue)
			creature->clearQueueAction(actioncntr);

		break;

	case ALREADYAFFECTEDJEDIPOWER:
			creature->sendSystemMessage("@jedi_spam:power_already_active"); // This target is already affected by that power.
			if (addToQueue)
				creature->clearQueueAction(actioncntr);

			break;

	case NOPRONE:
		if (addToQueue)
			creature->clearQueueAction(actioncntr, 0, 1, 7);

		break;

	case NOKNEELING:
		if (addToQueue)
			creature->clearQueueAction(actioncntr, 0, 1, 4);

		break;
	case INSUFFICIENTPERMISSION:
		creature->sendSystemMessage("@error_message:insufficient_permissions"); //You do not have sufficient permissions to perform the requested action.

		if (addToQueue)
			creature->clearQueueAction(actioncntr);
		break;
	case TOOCLOSE:
		prm.setStringId("combat_effects", "prone_ranged_too_close");
		creature->sendSystemMessage(prm);

		if (addToQueue)
			creature->clearQueueAction(actioncntr);
		break;
	case INSUFFICIENTHAM:
		prm.setStringId("cbt_spam", "pool_drain_fail_single");
		creature->sendSystemMessage(prm);

		if (addToQueue)
			creature->clearQueueAction(actioncntr);
		break;
	default:
		if (addToQueue)
			creature->clearQueueAction(actioncntr);
		break;
	}
}

void QueueCommand::onComplete(uint32 actioncntr, CreatureObject* player, float commandDuration) const {
	if (!player->isPlayerCreature())
		return;

	if (addToQueue) {
		player->clearQueueAction(actioncntr, commandDuration);
	}
}

int QueueCommand::doCommonMedicalCommandChecks(CreatureObject* creature) const {
	if (!checkStateMask(creature))
		return INVALIDSTATE;

	if (!checkInvalidLocomotions(creature))
		return INVALIDLOCOMOTION;

	if (creature->isProne() || creature->isMeditating() || creature->isSwimming()) {
		creature->sendSystemMessage("@error_message:wrong_state"); //You cannot complete that action while in your current state.
		return GENERALERROR;
	}

	if (creature->isRidingMount()) {
		creature->sendSystemMessage("@error_message:survey_on_mount"); //You cannot perform that action while mounted on a creature or driving a vehicle.
		return GENERALERROR;
	}

	return SUCCESS;
}

bool QueueCommand::checkForArenaDuel(CreatureObject* target) const {
	FrsManager* frsManager = server->getZoneServer()->getFrsManager();

	if (frsManager == nullptr)
		return false;

	if (!frsManager->isFrsEnabled())
		return false;

	return frsManager->isPlayerFightingInArena(target->getObjectID());
}

void QueueCommand::checkForTef(CreatureObject* creature, CreatureObject* target) const {
	if (creature == nullptr || target == nullptr)
		return;

	if (!creature->isPlayerCreature() || creature == target) {
		return;
	}

	PlayerObject* ghost = creature->getPlayerObject().get();

	if (ghost == nullptr) {
		return;
	}

	if (target->isPet()) {
		ManagedReference<CreatureObject*> owner = target->getLinkedCreature().get();

		if (owner == nullptr)
			return;

		target = owner;
	}

	if (target->isPlayerCreature() && !CombatManager::instance()->areInDuel(creature, target)) {
		PlayerObject* targetGhost = target->getPlayerObject().get();

		if (targetGhost != nullptr) {
			if (ConfigManager::instance()->useCovertOvertSystem()) {
				int healerStatus = creature->getFactionStatus();
				int targetStatus = target->getFactionStatus();

				if (creature->getFaction() == target->getFaction() && ((healerStatus >= FactionStatus::COVERT && targetGhost->hasGcwTef()) || (healerStatus == FactionStatus::COVERT && targetStatus == FactionStatus::OVERT))) {
					ghost->updateLastGcwPvpCombatActionTimestamp();
				}
			} else {
				if (target->getFactionStatus() == FactionStatus::OVERT && targetGhost->hasPvpTef()) {
					ghost->updateLastGcwPvpCombatActionTimestamp();
				}
			}

			if (targetGhost->isInPvpArea(true)) {
				ghost->updateLastPvpAreaCombatActionTimestamp();
			}
		}
	}
}

bool QueueCommand::checkCooldown(CreatureObject* creo) const {
	if (cooldown == 0) {
		return true;
	}

	if (creo == nullptr) {
		error() << "checkCooldown() creature is nullptr";
		return true;
	}

	// Provide sane default but should have been set in setCooldown()
	auto cooldownKey = cooldownName.isEmpty() ? "command_" + name : cooldownName;

	if (creo->checkCooldownRecovery(cooldownKey)) {
		creo->addCooldown(cooldownKey, cooldown);
		return true;
	}

	uint32 remain = 0;
	auto cooldownTime = creo->getCooldownTime(cooldownKey);

	if (cooldownTime != nullptr) {
		Time now;
		remain = now.miliDifference(*cooldownTime) / 1000;
	}

	String logMsg;

	if (!cooldownString.isEmpty()) {
		if (cooldownString.charAt(0) == '@') {
			StringIdChatParameter stringIdMsg(cooldownString);
			stringIdMsg.setDI(remain);
			logMsg = stringIdMsg.toString();
			creo->sendSystemMessage(stringIdMsg);
		} else {
			logMsg = cooldownString.replaceFirst("%DI", String::valueOf(remain));
			creo->sendSystemMessage(logMsg);
		}
	} else {
		StringBuffer buf;

		buf << "You can't do /" << name << " again yet, please wait";

		if (remain > 0) {
			buf << " " << remain << (remain == 1 ? " second" : " seconds");
		}

		buf << " before trying again.";
		logMsg = buf.toString();
		creo->sendSystemMessage(logMsg);
	}

	creo->info(admin) << "checkCooldown /" << name << ": remain=" << remain << "; msg=\"" << logMsg << "\"";

	return false;
}

String QueueCommand::getSyntax() const {
	return String("");
}

void QueueCommand::addInvalidLocomotion(int l) {
	invalidLocomotion.add(l);
}

bool QueueCommand::checkDistance(SceneObject* source, SceneObject* target, float range) const {
	return (source->getWorldPosition().distanceTo(target->getWorldPosition()) - source->getTemplateRadius() - target->getTemplateRadius() <= range);
}

bool QueueCommand::checkStateMask(CreatureObject* creature) const {
	return (creature->getStateBitmask() & stateMask) == 0;
}

bool QueueCommand::checkSpaceStates(CreatureObject* creature) const {
	return (creature->isPilotingShip() || creature->isInShipStation());
}

float QueueCommand::getCommandDuration(CreatureObject* object, const UnicodeString& arguments) const {
	// TODO: modify this value by skill, probably need to specify which skill affects what in luas
	return defaultTime;
}

void QueueCommand::setStateMask(uint64 mask) {
	stateMask = mask;
}

void QueueCommand::setDefaultTime(float time) {
	defaultTime = time;
}

void QueueCommand::setTargetType(int num) {
	targetType = num;
}

void QueueCommand::setDisabled(bool state) {
	disabled = state;
}

void QueueCommand::setDisabled(int state) {
	if (state == 0)
		disabled = false;
	else
		disabled = true;
}

void QueueCommand::setAddToCombatQueue(bool state) {
	addToQueue = state;
}

void QueueCommand::setAddToCombatQueue(int state) {
	if (state == 0)
		addToQueue = false;
	else
		addToQueue = true;
}

void QueueCommand::setCommandGroup(int val) {
	commandGroup = val;
}

void QueueCommand::setMaxRange(float r) {
	maxRangeToTarget = (int)r;
}

void QueueCommand::setCharacterAbility(const String& ability) {
	characterAbility = ability;

	if (ability == "admin") {
		admin = true;

		// Allow config to potentially override admin cmd cooldown
		if (cooldown == 0) {
			setCooldown(0);
		}
	}
}

void QueueCommand::setDefaultPriority(const String& priority) {
	if (priority == "immediate")
		defaultPriority = IMMEDIATE;
	else if (priority == "normal")
		defaultPriority = NORMAL;
	else if (priority == "front")
		defaultPriority = FRONT;
	else
		System::out << "Setting unknown priority " << priority << endl;
}

void QueueCommand::setDefaultPriority(const int priority) {
	if (priority < 0 || priority > 2)
		System::out << "Setting unknown priority " << priority << endl;
	else
		defaultPriority = priority;
}

uint64 QueueCommand::getStateMask() const {
	return stateMask;
}

bool QueueCommand::requiresAdmin() const {
	return admin;
}

int QueueCommand::getTargetType() const {
	return targetType;
}

String QueueCommand::getName() const {
	return name;
}

uint32 QueueCommand::getNameCRC() const {
	return nameCRC;
}

float QueueCommand::getMaxRange() const {
	return maxRangeToTarget;
}

const String& QueueCommand::getQueueCommandName() const {
	return name;
}

const String& QueueCommand::getCharacterAbility() const {
	return characterAbility;
}

float QueueCommand::getDefaultTime() const {
	return defaultTime;
}

int QueueCommand::getDefaultPriority() const {
	return defaultPriority;
}

bool QueueCommand::isDisabled() const {
	return disabled;
}

bool QueueCommand::addToCombatQueue() const {
	return addToQueue;
}

bool QueueCommand::isCombatCommand() const {
	return false;
}

bool QueueCommand::isForceHealCommand() const {
	return false;
}

bool QueueCommand::isJediQueueCommand() const {
	return false;
}

bool QueueCommand::isJediCombatCommand() const {
	return false;
}

bool QueueCommand::isJediCommand() const {
	return (isForceHealCommand() || isJediQueueCommand() || isJediCombatCommand());
}

int QueueCommand::getSkillModSize() const {
	return skillMods.size();
}

int QueueCommand::getSkillMod(int index, String& skillMod) const {
	skillMod = skillMods.elementAt(index).getKey();
	return skillMods.elementAt(index).getValue();
}

int QueueCommand::getCommandGroup() const {
	return commandGroup;
}

void QueueCommand::addSkillMod(const String& skillMod, const int value) {
	skillMods.put(skillMod, value);
}

bool QueueCommand::isWearingArmor(CreatureObject* creo) const {
	for (int i = 0; i < creo->getSlottedObjectsSize(); ++i) {
		SceneObject* item = creo->getSlottedObject(i);
		if (item != nullptr && item->isArmorObject())
			return true;
	}

	return false;
}

void QueueCommand::setCooldownString(String msg) {
	cooldownString = msg;
}

String QueueCommand::getCooldownString() const {
	return cooldownString;
}

void QueueCommand::setCooldownName(String name) {
	cooldownName = name;
}

String QueueCommand::getCooldownName() const {
	return cooldownName;
}

void QueueCommand::setCooldown(int cooldownMili) {
	cooldown = Math::max(0, ConfigManager::instance()->getInt("Core3.CommandCooldown." + name, cooldownMili));

	if (cooldown > 0 && cooldownName.isEmpty()) {
		cooldownName = "command_" + name;
	}

	if (cooldownMili == 0 && cooldown > 0) {
		info(true) << "setCooldown(" << cooldownMili << "): cooldown=" << cooldown << "; cooldownName=" << cooldownName;
	}
}

int QueueCommand::getCooldown() const {
	return cooldown;
}

void QueueCommand::handleBuff(SceneObject* creature, ManagedObject* object, int64 param) const {
}

String QueueCommand::toStringData() const {
	StringBuffer buf;
	buf << "QueueCommand(" << name << ", nameCRC=" << nameCRC << ", stateMask=" << stateMask << ", targetType=" << targetType << ", maxRangeToTarget=" << maxRangeToTarget << ", disabled=" << disabled << ", addToQueue=" << addToQueue << ", admin=" << admin << ", cooldown=" << cooldown << ", cooldownString=\""
		<< cooldownString << "\""
		<< ", defaultTime=" << defaultTime << ", characterAbility=" << characterAbility << ", defaultPriority=" << defaultPriority << ", commandGroup=" << commandGroup << ", invalidLocomotion=[";

	for (int i = 0; i < invalidLocomotion.size(); ++i) {
		if (i) {
			buf << ", ";
		}
		buf << invalidLocomotion.get(i);
	}

	buf << "], skillMods=[";

	for (int i = 0; i < skillMods.size(); ++i) {
		if (i) {
			buf << ", ";
		}
		buf << skillMods.get(i);
	}

	buf << "])";

	return buf.toString();
}