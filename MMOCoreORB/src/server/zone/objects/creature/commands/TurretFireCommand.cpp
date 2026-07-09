#include "TurretFireCommand.h"

TurretFireCommand::TurretFireCommand(const String& name, ZoneProcessServer* server) : CombatQueueCommand(name, server) {
}

int TurretFireCommand::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	if (!checkStateMask(creature))
		return INVALIDSTATE;

	if (!checkInvalidLocomotions(creature))
		return INVALIDLOCOMOTION;

	return SUCCESS;
}
