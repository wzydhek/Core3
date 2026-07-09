#include "ResourceContainerSplitCommand.h"
#include "server/zone/objects/scene/SceneObject.h"
#include "server/zone/objects/resource/ResourceContainer.h"

ResourceContainerSplitCommand::ResourceContainerSplitCommand(const String& name, ZoneProcessServer* server) : QueueCommand(name, server) {
}

int ResourceContainerSplitCommand::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	if (!checkStateMask(creature))
		return INVALIDSTATE;

	if (!checkInvalidLocomotions(creature))
		return INVALIDLOCOMOTION;

	StringTokenizer tokenizer(arguments.toString());
	int newStackSize = tokenizer.getIntToken();

	if (newStackSize < 1)
		return GENERALERROR;

	ManagedReference<ResourceContainer*> resourceContainer = server->getZoneServer()->getObject(target).castTo<ResourceContainer*>();

	if ((resourceContainer == nullptr || !resourceContainer->isResourceContainer() || !creature->isPlayerCreature()))
		return INVALIDTARGET;

	if (!resourceContainer->isASubChildOf(creature)) {
		creature->sendSystemMessage("@container_error_message:container08");
		return INVALIDTARGET;
	}

	ManagedReference<SceneObject*> objectsParent = resourceContainer->getParent().get();

	if (objectsParent == nullptr || objectsParent->isCellObject()) {
		creature->sendSystemMessage("@container_error_message:container03");
		return GENERALERROR;
	}

	if (objectsParent->isContainerFullRecursive()) {
		creature->sendSystemMessage("@error_message:inv_full"); // Your inventory is full.
		return GENERALERROR;
	}

	Locker clocker(resourceContainer, creature);

	resourceContainer->split(newStackSize);

	return SUCCESS;
}