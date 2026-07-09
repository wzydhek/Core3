#include "PolearmLunge1Command.h"

PolearmLunge1Command::PolearmLunge1Command(const String& name, ZoneProcessServer* server) : CombatQueueCommand(name, server) {
}

int PolearmLunge1Command::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	if (!checkStateMask(creature))
		return INVALIDSTATE;

	if (!checkInvalidLocomotions(creature))
		return INVALIDLOCOMOTION;

	int result = doCombatAction(creature, target);

	if (result == SUCCESS)
		creature->notifyObservers(ObserverEventType::ABILITYUSED, nullptr, STRING_HASHCODE("polearmlunge1"));

	return result;
}