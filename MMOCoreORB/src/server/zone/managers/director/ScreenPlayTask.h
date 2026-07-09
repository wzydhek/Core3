/*
 * ScreenPlayTask.h
 *
 *  Created on: 27/05/2011
 *      Author: victor
 */

#pragma once

#include "server/zone/managers/director/PersistentEvent.h"
#include "server/ServerCore.h"
#include "server/zone/ZoneServer.h"
#include "server/zone/objects/scene/SceneObject.h"

namespace server {
namespace zone {
namespace managers {
namespace director {

class ScreenPlayTask : public Task {
	ManagedWeakReference<SceneObject*> obj;
	String taskKey;
	String screenPlay;
	String args;
	Reference<PersistentEvent*> persistentEvent;
public:

	ScreenPlayTask(SceneObject* scno, const String& key, const String& playName, const String& arguments);

	void run();

	ManagedReference<SceneObject*> getSceneObject();

	const String& getTaskKey() const;

	const String& getScreenPlay() const;

	const String& getArgs() const;

	void setPersistentEvent(PersistentEvent* persistentEvent);

	Reference<PersistentEvent*>& getPersistentEvent();

	const Reference<PersistentEvent*>& getPersistentEvent() const;

};

} // namespace director
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::director;
