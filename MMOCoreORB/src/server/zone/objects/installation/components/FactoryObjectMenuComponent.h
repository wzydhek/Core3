/*
 * FactoryObjectMenuComponent.h
 *
 *  Created on: Feb 27, 2012
 *      Author: xyborn
 */

#pragma once

#include "engine/engine.h"
#include "server/zone/objects/installation/components/InstallationObjectMenuComponent.h"

namespace server {
namespace zone {
namespace objects {
namespace installation {
namespace components {

class FactoryObjectMenuComponent : public InstallationObjectMenuComponent {
public:
	void fillObjectMenuResponse(SceneObject* sceneObject, ObjectMenuResponse* menuResponse, CreatureObject* creature) const;
	int handleObjectMenuSelect(SceneObject* sceneObject, CreatureObject* creature, byte selectedID) const;
};

} // namespace components
} // namespace installation
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::installation::components;
