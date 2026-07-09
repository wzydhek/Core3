#include "PositionUpdateTask.h"

PositionUpdateTask::PositionUpdateTask(SceneObject* obj, TreeEntry* ent) {
	object = obj;
	entry = ent;
}

void PositionUpdateTask::run() {
	Locker locker(object);

	Locker clocker(entry, object);

	object->notifyObservers(ObserverEventType::OBJECTINRANGEMOVED, entry);
}
