/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "server/zone/objects/structure/components/StructureZoneComponent.h"
#include "server/zone/objects/scene/SceneObject.h"

namespace server {
namespace zone {
namespace objects {
namespace structure {
namespace components {

class GarageZoneComponent : public StructureZoneComponent {

public:
	void notifyPositionUpdate(SceneObject* sceneObject, TreeEntry* entry) const;
	void notifyDissapear(SceneObject* sceneObject, TreeEntry* entry) const;
};

} // namespace components
} // namespace structure
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::structure::components;
