#include "DeathCountCommand.h"

DeathCountCommand::DeathCountCommand(const String& name, ZoneProcessServer* server) : QueueCommand(name, server) {
}

int DeathCountCommand::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	if (!checkStateMask(creature))
		return INVALIDSTATE;

	if (!checkInvalidLocomotions(creature))
		return INVALIDLOCOMOTION;

	return SUCCESS;
}