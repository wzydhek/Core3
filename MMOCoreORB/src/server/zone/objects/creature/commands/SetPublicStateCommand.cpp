#include "SetPublicStateCommand.h"

SetPublicStateCommand::SetPublicStateCommand(const String& name, ZoneProcessServer* server) : QueueCommand(name, server) {
}

int SetPublicStateCommand::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	if (!checkStateMask(creature))
		return INVALIDSTATE;

	if (!checkInvalidLocomotions(creature))
		return INVALIDLOCOMOTION;

	return SUCCESS;
}