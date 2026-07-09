#include "FlushingShot2Command.h"

FlushingShot2Command::FlushingShot2Command(const String& name, ZoneProcessServer* server) : CombatQueueCommand(name, server) {
}

int FlushingShot2Command::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	if (!checkStateMask(creature))
		return INVALIDSTATE;

	if (!checkInvalidLocomotions(creature))
		return INVALIDLOCOMOTION;

	return doCombatAction(creature, target);
}