#include "ItemmovebackCommand.h"

ItemmovebackCommand::ItemmovebackCommand(const String& name, ZoneProcessServer* server) : QueueCommand(name, server) {
}

int ItemmovebackCommand::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	if (!checkStateMask(creature))
		return INVALIDSTATE;

	if (!checkInvalidLocomotions(creature))
		return INVALIDLOCOMOTION;

	creature->executeObjectControllerAction(0x4B74A403, target, "back 10");

	return SUCCESS;
}