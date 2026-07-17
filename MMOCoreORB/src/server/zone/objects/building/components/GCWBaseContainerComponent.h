/*
 * GCWBaseContainerComponent.h
 *
 *  Created on: Dec 6, 2012
 *      Author: root
 */

#pragma once

#include "server/zone/objects/building/BuildingObject.h"
#include "server/zone/objects/creature/CreatureObject.h"
#include "server/zone/objects/structure/components/StructureContainerComponent.h"

namespace server {
namespace zone {
namespace objects {
namespace building {
namespace components {

class GCWBaseContainerComponent : public StructureContainerComponent {
public:
	bool checkContainerPermission(SceneObject* sceneObject, CreatureObject* creature, uint16 permission) const;

	bool checkContainerPermission(BuildingObject* building, CreatureObject* creature, uint16 permission, bool sendMessage) const;

	bool checkPVPPermission(BuildingObject* building, CreatureObject* creature, uint16 permission, bool sendMessage) const;

	bool checkPVEPermission(BuildingObject* building, CreatureObject* creature, uint16 permission, bool sendMessage) const;

};

} // namespace components
} // namespace building
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::building::components;
