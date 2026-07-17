/*
 * ScannerZoneComponent.h
 *
 *  Created on: Dec 17, 2012
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

class ScannerZoneComponent : public GroundZoneComponent {

public:
	void notifyInsertToZone(SceneObject* sceneObject, Zone* zone) const;
	void notifyPositionUpdate(SceneObject* sceneObject, TreeEntry* entry) const;

};

} // namespace components
} // namespace installation
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::installation::components;
