#include "CommCommand.h"

CommCommand::CommCommand(const String& name, ZoneProcessServer* server) : QueueCommand(name, server) {
}

int CommCommand::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	if (!checkStateMask(creature))
		return INVALIDSTATE;

	if (!checkInvalidLocomotions(creature))
		return INVALIDLOCOMOTION;

	if (!creature->isPilotingShip())
		return INVALIDSTATE;

	return SUCCESS;
}