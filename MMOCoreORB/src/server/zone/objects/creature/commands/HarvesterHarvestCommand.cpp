#include "HarvesterHarvestCommand.h"

HarvesterHarvestCommand::HarvesterHarvestCommand(const String& name, ZoneProcessServer* server) : QueueCommand(name, server) {
}

int HarvesterHarvestCommand::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	if (!checkStateMask(creature))
		return INVALIDSTATE;

	if (!checkInvalidLocomotions(creature))
		return INVALIDLOCOMOTION;

	return SUCCESS;
}