#include "PolearmSweep1Command.h"

PolearmSweep1Command::PolearmSweep1Command(const String& name, ZoneProcessServer* server) : CombatQueueCommand(name, server) {
}

int PolearmSweep1Command::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	if (!checkStateMask(creature))
		return INVALIDSTATE;

	if (!checkInvalidLocomotions(creature))
		return INVALIDLOCOMOTION;

	return doCombatAction(creature, target);
}