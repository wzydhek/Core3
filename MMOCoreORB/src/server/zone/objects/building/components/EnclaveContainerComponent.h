#pragma once

#include "server/zone/objects/creature/CreatureObject.h"
#include "server/zone/objects/structure/components/StructureContainerComponent.h"

namespace server {
namespace zone {
namespace objects {
namespace building {
namespace components {

class EnclaveContainerComponent : public StructureContainerComponent {
public:
	bool checkContainerPermission(SceneObject* sceneObject, CreatureObject* creature, uint16 permission) const;
	bool checkBuildingPermission(SceneObject* sceneObject, CreatureObject* creature, uint16 permission) const;
	bool checkCellPermission(SceneObject* sceneObject, CreatureObject* creature, uint16 permission) const;
	int notifyObjectRemoved(SceneObject* sceneObject, SceneObject* object, SceneObject* destination) const;
};

} // namespace components
} // namespace building
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::building::components;
