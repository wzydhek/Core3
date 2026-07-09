#include "ForceCommandCommand.h"

ForceCommandCommand::ForceCommandCommand(const String& name, ZoneProcessServer* server) : QueueCommand(name, server) {
}

int ForceCommandCommand::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	if (!checkStateMask(creature))
		return INVALIDSTATE;

	if (!checkInvalidLocomotions(creature))
		return INVALIDLOCOMOTION;

	return SUCCESS;
}