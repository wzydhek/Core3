/*
 * EventPerkActorContainerComponent.h
 *
 * Created on: 2024-04-26
 * By: Hakry
 */

#pragma once

#include "server/zone/objects/scene/components/ContainerComponent.h"

namespace server {
namespace zone {
namespace objects {
namespace tangible {
namespace components {

class EventPerkActorContainerComponent : public ContainerComponent {
public:
	virtual bool checkContainerPermission(SceneObject* sceneObject, CreatureObject* creature, uint16 permission) const;
};

} // namespace components
} // namespace tangible
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::tangible::components;
