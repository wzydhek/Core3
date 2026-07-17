
#pragma once

#include "engine/engine.h"
#include "server/zone/objects/scene/SceneObject.h"
#include "server/zone/objects/cell/CellObject.h"

namespace server {
 namespace zone {
  namespace objects {
   namespace scene {

class UnloadContainerTask : public Task {
	ManagedWeakReference<SceneObject*> container;

	public:
		UnloadContainerTask(SceneObject* obj);

		void run();
	};

   }
  }
 }
} // namespace server

 using namespace server::zone::objects::scene;
