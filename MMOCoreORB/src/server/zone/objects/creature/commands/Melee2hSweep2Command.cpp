#include "Melee2hSweep2Command.h"

Melee2hSweep2Command::Melee2hSweep2Command(const String& name, ZoneProcessServer* server) : CombatQueueCommand(name, server) {
}

int Melee2hSweep2Command::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	if (!checkStateMask(creature))
		return INVALIDSTATE;

	if (!checkInvalidLocomotions(creature))
		return INVALIDLOCOMOTION;

	return doCombatAction(creature, target);
}