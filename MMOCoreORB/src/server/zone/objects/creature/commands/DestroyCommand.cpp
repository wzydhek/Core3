#include "DestroyCommand.h"

DestroyCommand::DestroyCommand(const String& name, ZoneProcessServer* server) : QueueCommand(name, server) {
}

int DestroyCommand::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	if (!checkStateMask(creature))
		return INVALIDSTATE;

	if (!checkInvalidLocomotions(creature))
		return INVALIDLOCOMOTION;

	// Note: This command doesn't do anything...

	return SUCCESS;
}