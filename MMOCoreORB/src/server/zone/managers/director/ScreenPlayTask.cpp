#include "ScreenPlayTask.h"
#include "server/zone/managers/director/DirectorManager.h"

ScreenPlayTask::ScreenPlayTask(SceneObject* scno, const String& key, const String& playName, const String& arguments) {
	obj = scno;
	taskKey = key;
	screenPlay = playName;
	args = arguments;
	persistentEvent = nullptr;
}

void ScreenPlayTask::run() {
	ZoneServer* zoneServer = ServerCore::getZoneServer();

	if (zoneServer == nullptr || zoneServer->isServerShuttingDown())
		return;

	if (zoneServer->isServerLoading()) {
		schedule(10000);

		return;
	}

	ManagedReference<SceneObject*> obj = this->obj.get();

	if (obj != nullptr) {
		Locker locker(obj);

		DirectorManager::instance()->activateEvent(this);
	} else {
		DirectorManager::instance()->activateEvent(this);
	}

	setTaskName(String("ScreenPlayTask " + screenPlay + ":" + taskKey + ":" + args).toCharArray());
}

ManagedReference<SceneObject*> ScreenPlayTask::getSceneObject() {
	return obj.get();
}

const String& ScreenPlayTask::getTaskKey() const {
	return taskKey;
}

const String& ScreenPlayTask::getScreenPlay() const {
	return screenPlay;
}

const String& ScreenPlayTask::getArgs() const {
	return args;
}

void ScreenPlayTask::setPersistentEvent(PersistentEvent* persistentEvent) {
	this->persistentEvent = persistentEvent;
}

Reference<PersistentEvent*>& ScreenPlayTask::getPersistentEvent() {
	return persistentEvent;
}

const Reference<PersistentEvent*>& ScreenPlayTask::getPersistentEvent() const {
	return persistentEvent;
}