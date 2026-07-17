/*
 * TurretZoneComponent.h
 *
 *  Created on: Nov 20, 2012
 *      Author: root
 */

#pragma once

#include "engine/engine.h"
#include "server/zone/objects/scene/SceneObject.h"
#include "server/zone/TreeEntry.h"

namespace server {
namespace zone {
namespace objects {
namespace installation {
namespace components {

class TurretZoneComponent : public GroundZoneComponent {

public:
	void notifyInsertToZone(SceneObject* sceneObject, Zone* zone) const;
	void notifyRemoveFromZone(SceneObject* sceneObject) const;

	void notifyInsert(SceneObject* sceneObject, TreeEntry* entry) const;
	void notifyDissapear(SceneObject* sceneObject, TreeEntry* entry) const;

	void notifyPositionUpdate(SceneObject* sceneObject, TreeEntry* entry) const;
};

} // namespace components
} // namespace installation
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::installation::components;
