#include "BaseDestructionTask.h"

BaseDestructionTask::BaseDestructionTask(GCWManager* manager, BuildingObject* building) {
	gcwManager = manager;
	buildingObject = building;
	countDown = manager->getDestructionTimer() / 60;
}

void BaseDestructionTask::run() {
	countDown--;
	ManagedReference<GCWManager*> strongRef = gcwManager.get();
	ManagedReference<BuildingObject*> building = buildingObject.get();
	if (strongRef == nullptr) {
		return;
	}

	strongRef->doBaseDestruction(building);
}

int BaseDestructionTask::getCountdown() {
	return countDown;
}