/*
 * StructureTerminalMenuComponent.h
 *
 *  Created on: Feb 26, 2012
 *      Author: swgemu
 */

#pragma once

#include "engine/engine.h"
#include "server/zone/objects/scene/components/ObjectMenuComponent.h"

namespace server {
namespace zone {
namespace objects {
namespace tangible {
namespace terminal {
namespace components {

class StructureTerminalMenuComponent : public ObjectMenuComponent {
public:
	void fillObjectMenuResponse(SceneObject* sceneObject, ObjectMenuResponse* menuResponse, CreatureObject* creature) const;
	int handleObjectMenuSelect(SceneObject* sceneObject, CreatureObject* creature, byte selectedID) const;
};

} // namespace components
} // namespace terminal
} // namespace tangible
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::tangible::terminal::components;
