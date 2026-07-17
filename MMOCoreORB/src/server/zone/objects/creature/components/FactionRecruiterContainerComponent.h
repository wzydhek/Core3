
#pragma once

#include "server/zone/objects/scene/components/ContainerComponent.h"

namespace server {
namespace zone {
namespace objects {
namespace creature {
namespace components {

class FactionRecruiterContainerComponent: public ContainerComponent {
public:

	int canAddObject(SceneObject* sceneObject, SceneObject* object, int containmentType, String& errorDescription) const;

	bool transferObject(SceneObject* sceneObject, SceneObject* object, int containmentType, bool notifyClient = false, bool allowOverflow = false, bool notifyRoot = true) const;

};

} // namespace components
} // namespace creature
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::creature::components;
