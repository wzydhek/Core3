#include "TumbleToKneelingCommand.h"
#include "templates/params/creature/CreatureAttribute.h"
#include "server/zone/ZoneServer.h"
#include "server/zone/objects/creature/buffs/StateBuff.h"

TumbleToKneelingCommand::TumbleToKneelingCommand(const String& name, ZoneProcessServer* server) : QueueCommand(name, server) {
}

int TumbleToKneelingCommand::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	if (!checkStateMask(creature))
		return INVALIDSTATE;

	if (!checkInvalidLocomotions(creature))
		return INVALIDLOCOMOTION;

	// Check for and deduct HAM cost.
	int actionCost = creature->calculateCostAdjustment(CreatureAttribute::QUICKNESS, 100);
	if (creature->getHAM(CreatureAttribute::ACTION) <= actionCost)
		return INSUFFICIENTHAM;

	creature->inflictDamage(creature, CreatureAttribute::ACTION, actionCost, true);

	creature->setPosture(CreaturePosture::CROUCHED, false, true);

	Reference<CreatureObject*> defender = server->getZoneServer()->getObject(target).castTo<CreatureObject*>();
	if (defender == nullptr)
		creature->doCombatAnimation(creature, STRING_HASHCODE("tumble"), 0, 0xFF);
	else
		creature->doCombatAnimation(defender, STRING_HASHCODE("tumble_facing"), 0, 0xFF);

	if (creature->isDizzied() && System::random(100) < 85) {
		creature->queueDizzyFallEvent();
	} else {
		Reference<StateBuff*> buff = new StateBuff(creature, CreatureState::TUMBLING, 1);

		Locker locker(buff);

		buff->setSkillModifier("melee_defense", 50);
		buff->setSkillModifier("ranged_defense", 50);

		creature->addBuff(buff);

		locker.release();

		creature->sendStateCombatSpam("cbt_spam", "tum_kneel", 0);
	}

	return SUCCESS;
}