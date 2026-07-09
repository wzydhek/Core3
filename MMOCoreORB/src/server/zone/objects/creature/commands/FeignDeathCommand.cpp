#include "FeignDeathCommand.h"
#include "server/zone/objects/creature/buffs/SingleUseBuff.h"
#include "server/zone/objects/scene/SceneObject.h"

FeignDeathCommand::FeignDeathCommand(const String& name, ZoneProcessServer* server) : QueueCommand(name, server) {
}

int FeignDeathCommand::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	if (!checkStateMask(creature))
		return INVALIDSTATE;

	if (!checkInvalidLocomotions(creature))
		return INVALIDLOCOMOTION;

	if (!creature->isInCombat()) {
		creature->sendSystemMessage("@combat_effects:feign_no_combat");
		return GENERALERROR;
	}

	Vector<uint32> observerTypes;
	observerTypes.add(ObserverEventType::DAMAGERECEIVED);

	ManagedReference<SingleUseBuff*> buff = new SingleUseBuff(creature, STRING_HASHCODE("private_feign_buff"), std::numeric_limits<float>::max(), BuffType::OTHER, getNameCRC());

	Locker locker(buff, creature); // buff->init requires buff to be locked

	buff->init(&observerTypes);
	buff->setSkillModifier("private_defense", -99999999);

	creature->addBuff(buff);

	creature->sendSystemMessage("@cbt_spam:feign_get_hit_single");

	return SUCCESS;
}

void FeignDeathCommand::handleBuff(SceneObject* creature, ManagedObject* object, int64 param) const {
	if (creature == nullptr || !creature->isCreatureObject())
		return;

	ManagedReference<CreatureObject*> creo = creature->asCreatureObject();

	if (creo == nullptr)
		return;

	Locker lock(creo);

	if (creo->hasState(CreatureState::FEIGNDEATH)) {
		creo->removeFeignedDeath();
	} else {
		if (creo->canFeignDeath()) {
			creo->feignDeath();
		} else {
			creo->sendSystemMessage("@cbt_spam:feign_fail_single");
		}
	}

	creo->removeBuff(STRING_HASHCODE("private_feign_buff"));
}