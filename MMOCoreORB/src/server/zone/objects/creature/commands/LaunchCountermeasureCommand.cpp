#include "LaunchCountermeasureCommand.h"

LaunchCountermeasureCommand::LaunchCountermeasureCommand(const String& name, ZoneProcessServer* server) : CombatQueueCommand(name, server) {
}

int LaunchCountermeasureCommand::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	if (!checkStateMask(creature))
		return INVALIDSTATE;

	if (!checkInvalidLocomotions(creature))
		return INVALIDLOCOMOTION;

	return doCombatAction(creature, target);
}