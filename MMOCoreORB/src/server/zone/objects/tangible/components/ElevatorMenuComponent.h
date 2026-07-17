/*
 * ElevatorMenuComponent.h
 *
 *  Created on: 06/24/2012
 *      Author: swgemu
 */

#pragma once

#include "TangibleObjectMenuComponent.h"

namespace server {
namespace zone {
namespace objects {
namespace tangible {
namespace components {

class ElevatorMenuComponent : public TangibleObjectMenuComponent {
protected:
public:
	virtual void fillObjectMenuResponse(SceneObject* sceneObject, ObjectMenuResponse* menuResponse, CreatureObject* player) const;
	virtual int handleObjectMenuSelect(SceneObject* sceneObject, CreatureObject* player, byte selectedID) const;
};

} // namespace components
} // namespace tangible
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::tangible::components;
