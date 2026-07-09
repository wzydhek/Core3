#include "OverChargeShot1Command.h"

OverChargeShot1Command::OverChargeShot1Command(const String& name, ZoneProcessServer* server) : CombatQueueCommand(name, server) {
}

int OverChargeShot1Command::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	if (!checkStateMask(creature))
		return INVALIDSTATE;

	if (!checkInvalidLocomotions(creature))
		return INVALIDLOCOMOTION;

	int result = doCombatAction(creature, target);

	if (result == SUCCESS)
		creature->notifyObservers(ObserverEventType::ABILITYUSED, nullptr, STRING_HASHCODE("overchargeshot1"));

	return result;
}