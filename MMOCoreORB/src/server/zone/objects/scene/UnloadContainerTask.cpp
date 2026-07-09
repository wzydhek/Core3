#include "UnloadContainerTask.h"

UnloadContainerTask::UnloadContainerTask(SceneObject* obj) {
	container = obj;
}

void UnloadContainerTask::run() {
	ManagedReference<SceneObject*> obj = container;

	if (obj == nullptr)
		return;

	if (obj->getLastContainerAccess() < 900000) { // if accessed within the last 15 minutes, reschedule
		reschedule(1800000);					  // 30 minutes
		return;
	}

	if (obj->isCellObject()) {
		CellObject* cell = obj.castTo<CellObject*>();

		if (cell->hasForceLoadObject()) {
			reschedule(1800000); // 30 minutes
			return;
		}
	}

	obj->unloadContainerObjects();
}