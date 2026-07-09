#include "ItemmoveupCommand.h"

ItemmoveupCommand::ItemmoveupCommand(const String& name, ZoneProcessServer* server) : QueueCommand(name, server) {
}

int ItemmoveupCommand::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	if (!checkStateMask(creature))
		return INVALIDSTATE;

	if (!checkInvalidLocomotions(creature))
		return INVALIDLOCOMOTION;

	creature->executeObjectControllerAction(0x4B74A403, target, "up 10");

	return SUCCESS;
}