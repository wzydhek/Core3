#include "GetMapLocationsCommand.h"

GetMapLocationsCommand::GetMapLocationsCommand(const String& name, ZoneProcessServer* server) : QueueCommand(name, server) {
}

int GetMapLocationsCommand::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	if (!checkStateMask(creature))
		return INVALIDSTATE;

	if (!checkInvalidLocomotions(creature))
		return INVALIDLOCOMOTION;

	return SUCCESS;
}