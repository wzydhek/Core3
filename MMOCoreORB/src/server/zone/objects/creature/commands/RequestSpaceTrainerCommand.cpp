#include "RequestSpaceTrainerCommand.h"

RequestSpaceTrainerCommand::RequestSpaceTrainerCommand(const String& name, ZoneProcessServer* server) : CombatQueueCommand(name, server) {
}

int RequestSpaceTrainerCommand::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	if (!checkStateMask(creature))
		return INVALIDSTATE;

	if (!checkInvalidLocomotions(creature))
		return INVALIDLOCOMOTION;

	return doCombatAction(creature, target);
}