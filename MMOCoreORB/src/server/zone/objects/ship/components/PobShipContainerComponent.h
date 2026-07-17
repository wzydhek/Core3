/*
 * PobShipContainerComponent.h
 */

#pragma once

#include "server/zone/objects/ship/components/ShipContainerComponent.h"

namespace server {
namespace zone {
namespace objects {
namespace ship {
namespace components {

class PobShipContainerComponent : public ShipContainerComponent {
public:
	bool checkContainerPermission(SceneObject* sceneObject, CreatureObject* creature, uint16 permission) const;
};

} // namespace components
} // namespace ship
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::ship::components;
