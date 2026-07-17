/*
 * WarrenDiskContainerComponent.h
 *
 * Created: 2024-04-20
 * By: Hakry
 *
 *
*/

#pragma once

#include "server/zone/objects/scene/components/ContainerComponent.h"
#include "server/zone/objects/creature/CreatureObject.h"

namespace server {
namespace zone {
namespace objects {
namespace intangible {
namespace components {

class WarrenDiskContainerComponent : public ContainerComponent {
public:
	bool checkContainerPermission(SceneObject* sceneObject, CreatureObject* creature, uint16 permission) const;
};

} // namespace components
} // namespace intangible
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::intangible::components;
