/*
 * SpaceZoneComponent.h
 *
 *  Created on: 26/05/2011
 *      Author: victor
 */

#pragma once

#include "engine/engine.h"
#include "SceneObjectComponent.h"

namespace server {
namespace zone {
namespace objects {
namespace scene {
class SceneObject;
}
} // namespace objects

class SpaceZone;
} // namespace zone
} // namespace server

using namespace server::zone::objects::scene;
using namespace server::zone;

#include "server/zone/TreeEntry.h"

namespace server {
namespace zone {
namespace objects {
namespace scene {
namespace components {

class SpaceZoneComponent : public SceneObjectComponent, public Logger {
protected:
	void insertChildObjectsToZone(SceneObject* sceneObject, SpaceZone* zone) const;

public:
	SpaceZoneComponent();

	virtual void notifyInsertToZone(SceneObject* sceneObject, SpaceZone* zone) const;

	virtual void switchZone(SceneObject* sceneObject, const String& newTerrainName, float newPostionX, float newPositionZ, float newPositionY, uint64 parentID = 0, bool toggleInvisibility = false, int playerArrangement = -1) const;

	virtual void teleport(SceneObject* sceneObject, float newPositionX, float newPositionZ, float newPositionY, uint64 parentID = 0) const;

	virtual void notifyRemoveFromZone(SceneObject* sceneObject) const;

	virtual void updateZone(SceneObject* sceneObject, bool lightUpdate, bool sendPackets = true) const;

	virtual void updateZoneWithParent(SceneObject* sceneObject, SceneObject* newParent, bool lightUpdate, bool sendPackets = true) const;

	virtual void notifyPositionUpdate(SceneObject* sceneObject, TreeEntry* entry) const {};

	virtual void notifySelfPositionUpdate(SceneObject* sceneObject) const;

	virtual void notifyInsert(SceneObject* sceneObject, TreeEntry* entry) const {};

	virtual void notifyDissapear(SceneObject* sceneObject, TreeEntry* entry) const {};

	void updateInRangeObjectsOnMount(SceneObject* sceneObject) const;

	virtual void destroyObjectFromWorld(SceneObject* sceneObject, bool sendSelfDestroy) const;

	void removeObjectFromZone(SceneObject* sceneObject, SpaceZone* zone, SceneObject* par) const;

	static void removeAllObjectsFromCOV(CloseObjectsVector* closeobjects, SortedVector<ManagedReference<TreeEntry*>>& closeSceneObjects, SceneObject* sceneObject, SceneObject* vectorOwner);
};

} // namespace components
} // namespace scene
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::scene::components;
