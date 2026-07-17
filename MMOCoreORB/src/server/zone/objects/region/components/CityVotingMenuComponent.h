/*
 * CityVotingMenuComponent.h
 *
 *  Created on: Feb 12, 2012
 *      Author: xyborn
 */

#pragma once

#include "server/zone/objects/scene/components/ObjectMenuComponent.h"

namespace server {
namespace zone {
namespace objects {
namespace region {
namespace components {

class CityVotingMenuComponent : public ObjectMenuComponent {
public:
	virtual void fillObjectMenuResponse(SceneObject* sceneObject, ObjectMenuResponse* menuResponse, CreatureObject* player) const;
	virtual int handleObjectMenuSelect(SceneObject* sceneObject, CreatureObject* player, byte selectedID) const;
};

} // namespace components
} // namespace region
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::region::components;
