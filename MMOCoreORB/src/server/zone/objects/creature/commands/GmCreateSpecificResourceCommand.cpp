#include "GmCreateSpecificResourceCommand.h"
#include "server/zone/managers/resource/ResourceManager.h"

GmCreateSpecificResourceCommand::GmCreateSpecificResourceCommand(const String& name, ZoneProcessServer* server) : QueueCommand(name, server) {
}

int GmCreateSpecificResourceCommand::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	if (!checkStateMask(creature))
		return INVALIDSTATE;

	if (!checkInvalidLocomotions(creature))
		return INVALIDLOCOMOTION;

	if (!creature->isPlayerCreature())
		return INVALIDPARAMETERS;

	ManagedReference<ResourceManager*> resourceManager = server->getZoneServer()->getResourceManager();
	resourceManager->createResourceSpawn(creature, arguments);

	return SUCCESS;
}