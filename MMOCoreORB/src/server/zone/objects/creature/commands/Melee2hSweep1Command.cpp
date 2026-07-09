#include "Melee2hSweep1Command.h"

Melee2hSweep1Command::Melee2hSweep1Command(const String& name, ZoneProcessServer* server) : CombatQueueCommand(name, server) {
}

int Melee2hSweep1Command::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	if (!checkStateMask(creature))
		return INVALIDSTATE;

	if (!checkInvalidLocomotions(creature))
		return INVALIDLOCOMOTION;

	return doCombatAction(creature, target);
}