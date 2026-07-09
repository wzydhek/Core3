#include "RevokePaidAccessTask.h"

RevokePaidAccessTask::RevokePaidAccessTask(BuildingObject* build) : Task() {
	building = build;
}

void RevokePaidAccessTask::run() {
	ManagedReference<BuildingObject*> strongRef = building;

	if (strongRef == nullptr) {
		return;
	}

	Locker _lock(strongRef);
	strongRef->updatePaidAccessList();
}