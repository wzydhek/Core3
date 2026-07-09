#include "GmCreateClassResourceCommand.h"
#include "server/zone/managers/resource/ResourceManager.h"

GmCreateClassResourceCommand::GmCreateClassResourceCommand(const String& name, ZoneProcessServer* server) : QueueCommand(name, server) {
}

int GmCreateClassResourceCommand::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	if (!checkStateMask(creature))
		return INVALIDSTATE;

	if (!checkInvalidLocomotions(creature))
		return INVALIDLOCOMOTION;

	ManagedReference<ResourceManager*> resourceManager = server->getZoneServer()->getResourceManager();
	resourceManager->createResourceSpawn(creature, arguments);

	return SUCCESS;
}