#include "UnarmedLunge1Command.h"

UnarmedLunge1Command::UnarmedLunge1Command(const String& name, ZoneProcessServer* server) : CombatQueueCommand(name, server) {
}

int UnarmedLunge1Command::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	if (!checkStateMask(creature))
		return INVALIDSTATE;

	if (!checkInvalidLocomotions(creature))
		return INVALIDLOCOMOTION;

	int result = doCombatAction(creature, target);

	if (result == SUCCESS)
		creature->notifyObservers(ObserverEventType::ABILITYUSED, nullptr, STRING_HASHCODE("unarmedlunge1"));

	return result;
}