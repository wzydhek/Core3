#include "Melee1hLunge2Command.h"

Melee1hLunge2Command::Melee1hLunge2Command(const String& name, ZoneProcessServer* server) : CombatQueueCommand(name, server) {
}

int Melee1hLunge2Command::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	if (!checkStateMask(creature))
		return INVALIDSTATE;

	if (!checkInvalidLocomotions(creature))
		return INVALIDLOCOMOTION;

	return doCombatAction(creature, target);
}