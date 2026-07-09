#include "SpawnStatusCommand.h"
#include "server/zone/objects/creature/ai/AiAgent.h"

SpawnStatusCommand::SpawnStatusCommand(const String& name, ZoneProcessServer* server) : QueueCommand(name, server) {
}

int SpawnStatusCommand::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	if (!checkStateMask(creature))
		return INVALIDSTATE;

	if (!checkInvalidLocomotions(creature))
		return INVALIDLOCOMOTION;

	return SUCCESS;
}