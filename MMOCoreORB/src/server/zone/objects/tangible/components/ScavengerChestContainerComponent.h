#pragma once

#include "server/zone/objects/scene/components/ContainerComponent.h"

namespace server {
namespace zone {
namespace objects {
namespace tangible {
namespace components {

class ScavengerChestContainerComponent: public ContainerComponent {
public:
	bool checkContainerPermission(SceneObject* container, CreatureObject* creature, uint16 permission) const;
	int notifyObjectRemoved(SceneObject* container, SceneObject*, SceneObject* destination) const;
	int canAddObject(SceneObject* sceneObject, SceneObject* object, int containmentType, String& errorDescription) const;
};

} // namespace components
} // namespace tangible
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::tangible::components;
