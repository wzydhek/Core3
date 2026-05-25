/*
 * PositionUpdateTask.h
 *
 *  Created on: 27/05/2011
 *      Author: victor
 */

#pragma once

#include "engine/engine.h"
#include "server/zone/objects/scene/SceneObject.h"

class PositionUpdateTask : public Task {
	ManagedReference<SceneObject*> object;
	ManagedReference<TreeEntry*> entry;
public:
	PositionUpdateTask(SceneObject* obj, TreeEntry* ent) {
		object = obj;
		entry = ent;
	}

	void run() {
		Locker locker(object);

		Locker clocker(entry, object);

		object->notifyObservers(ObserverEventType::OBJECTINRANGEMOVED, entry);
	}
};
