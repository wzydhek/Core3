/*
 * ForceCrystalMenuComponent.h
 */

#pragma once

#include "TangibleObjectMenuComponent.h"

namespace server {
namespace zone {
namespace objects {
namespace tangible {
namespace components {

class ForceCrystalMenuComponent : public TangibleObjectMenuComponent {
public:
	virtual int handleObjectMenuSelect(SceneObject* sceneObject, CreatureObject* player, byte selectedID) const;

	virtual void fillObjectMenuResponse(SceneObject* sceneObject, ObjectMenuResponse* menuResponse, CreatureObject* player) const;

};

} // namespace components
} // namespace tangible
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::tangible::components;
