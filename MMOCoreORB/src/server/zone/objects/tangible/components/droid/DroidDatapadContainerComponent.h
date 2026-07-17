/*
 * DroidDatapadContainerComponent.h
 */

#pragma once

#include "server/zone/objects/scene/components/ContainerComponent.h"

namespace server {
namespace zone {
namespace objects {
namespace tangible {
namespace components {
namespace droid {

class DroidDatapadContainerComponent : public ContainerComponent {
public:
	bool checkContainerPermission(SceneObject* sceneObject, CreatureObject* creature, uint16 permission) const;

	int canAddObject(SceneObject* sceneObject, SceneObject* object, int containmentType, String& errorDescription) const;

	bool isDataPadContainer() const;
};

} // namespace droid
} // namespace components
} // namespace tangible
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::tangible::components::droid;
