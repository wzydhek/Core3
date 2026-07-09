#include "ResourceShiftTask.h"

ResourceShiftTask::ResourceShiftTask(ManagedReference<ResourceManager*> resMan) {
	resourceManager = resMan;

	setCustomTaskQueue("slowQueue");
}

void ResourceShiftTask::run() {
	ZoneServer* server = resourceManager->getZoneServer();

	if (server == nullptr || server->isServerShuttingDown())
		return;

	resourceManager->shiftResources();
}