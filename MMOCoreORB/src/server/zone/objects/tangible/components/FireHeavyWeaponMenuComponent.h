/*
 * FireHeavyWeaponMenuComponent.h
 *
 *  Created on: May 10, 2012
 *      Author: chris.rush
 */

#pragma once

#include "WeaponObjectMenuComponent.h"

namespace server {
namespace zone {
namespace objects {
namespace tangible {
namespace components {

class FireHeavyWeaponMenuComponent : public WeaponObjectMenuComponent {
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
