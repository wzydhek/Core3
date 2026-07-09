#include "TransferItemCommand.h"

TransferItemCommand::TransferItemCommand(const String& name, ZoneProcessServer* server) : QueueCommand(name, server) {
}

int TransferItemCommand::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	if (!checkStateMask(creature))
		return INVALIDSTATE;

	if (!checkInvalidLocomotions(creature))
		return INVALIDLOCOMOTION;

	// creature->info("transfer item command");
	return SUCCESS;
}