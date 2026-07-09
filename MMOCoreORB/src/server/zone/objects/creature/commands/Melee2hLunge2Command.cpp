#include "Melee2hLunge2Command.h"

Melee2hLunge2Command::Melee2hLunge2Command(const String& name, ZoneProcessServer* server) : CombatQueueCommand(name, server) {
}

int Melee2hLunge2Command::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	if (!checkStateMask(creature))
		return INVALIDSTATE;

	if (!checkInvalidLocomotions(creature))
		return INVALIDLOCOMOTION;

	return doCombatAction(creature, target);
}