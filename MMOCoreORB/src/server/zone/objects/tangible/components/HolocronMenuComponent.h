/*
 * HolocronMenuComponent.h
 *
 *  Created on: 01/23/2012
 *      Author: xyborn
 */

#pragma once

#include "TangibleObjectMenuComponent.h"

namespace server {
namespace zone {
namespace objects {
namespace tangible {
namespace components {

class HolocronMenuComponent : public TangibleObjectMenuComponent {
public:
	int handleObjectMenuSelect(SceneObject* sceneObject, CreatureObject* player, byte selectedID) const;
};

} // namespace components
} // namespace tangible
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::tangible::components;
