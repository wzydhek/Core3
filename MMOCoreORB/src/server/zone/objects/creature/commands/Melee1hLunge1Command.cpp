#include "Melee1hLunge1Command.h"

Melee1hLunge1Command::Melee1hLunge1Command(const String& name, ZoneProcessServer* server) : CombatQueueCommand(name, server) {
}

int Melee1hLunge1Command::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	if (!checkStateMask(creature))
		return INVALIDSTATE;

	if (!checkInvalidLocomotions(creature))
		return INVALIDLOCOMOTION;

	int result = doCombatAction(creature, target);

	if (result == SUCCESS)
		creature->notifyObservers(ObserverEventType::ABILITYUSED, nullptr, STRING_HASHCODE("melee1hlunge1"));

	return result;
}