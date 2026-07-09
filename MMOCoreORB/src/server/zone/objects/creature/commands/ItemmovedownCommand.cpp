#include "ItemmovedownCommand.h"

ItemmovedownCommand::ItemmovedownCommand(const String& name, ZoneProcessServer* server) : QueueCommand(name, server) {
}

int ItemmovedownCommand::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	if (!checkStateMask(creature))
		return INVALIDSTATE;

	if (!checkInvalidLocomotions(creature))
		return INVALIDLOCOMOTION;

	creature->executeObjectControllerAction(0x4B74A403, target, "down 10");

	return SUCCESS;
}