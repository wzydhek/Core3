#pragma once

#include "server/zone/objects/scene/components/GroundZoneComponent.h"

namespace server {
namespace zone {
namespace objects {
namespace tangible {
namespace components {

class PersonnelPerkZoneComponent : public GroundZoneComponent {

public:
	void notifyInsertToZone(SceneObject* sceneObject, Zone* zne) const;
};

} // namespace components
} // namespace tangible
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::tangible::components;
