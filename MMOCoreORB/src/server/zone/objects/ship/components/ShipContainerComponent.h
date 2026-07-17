/*
 * PobShipContainerComponent.h
 */

#pragma once

#include "server/zone/objects/scene/components/ContainerComponent.h"

namespace server {
namespace zone {
namespace objects {
namespace ship {
namespace components {

class ShipContainerComponent : public ContainerComponent, public Logger {
public:
	ShipContainerComponent();

	virtual bool checkContainerPermission(SceneObject* sceneObject, CreatureObject* creature, uint16 permission) const;
	virtual bool transferObject(SceneObject* sceneObject, SceneObject* object, int containmentType, bool notifyClient = false, bool allowOverflow = false, bool notifyRoot = true) const;
};

} // namespace components
} // namespace ship
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::ship::components;
