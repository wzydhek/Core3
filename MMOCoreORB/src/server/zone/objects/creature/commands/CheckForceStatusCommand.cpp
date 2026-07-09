#include "CheckForceStatusCommand.h"
#include "server/zone/managers/jedi/JediManager.h"

CheckForceStatusCommand::CheckForceStatusCommand(const String& name, ZoneProcessServer* server) : QueueCommand(name, server) {
}

int CheckForceStatusCommand::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	if (!checkStateMask(creature))
		return INVALIDSTATE;

	if (!checkInvalidLocomotions(creature))
		return INVALIDLOCOMOTION;

	JediManager::instance()->checkForceStatusCommand(creature);

	return SUCCESS;
}