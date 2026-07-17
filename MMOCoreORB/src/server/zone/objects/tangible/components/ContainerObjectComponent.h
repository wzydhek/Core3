/*
 * ContainerObjectComponent.h
 *
 *  Created on: 07/02/2012
 *      Author: victor
 */

#pragma once

#include "server/zone/objects/scene/components/ContainerComponent.h"

namespace server {
namespace zone {
namespace objects {
namespace tangible {
namespace components {

class ContainerObjectComponent : public ContainerComponent {
public:
	bool checkContainerPermission(SceneObject* sceneObject, CreatureObject* creature, uint16 permission) const;
};

} // namespace components
} // namespace tangible
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::tangible::components;
