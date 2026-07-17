/*
 * PlaceDecorationComponent.h
 *
 *  Created on: Apr 8, 2013
 *      Author: root
 */

#pragma once

#include "server/zone/objects/tangible/deed/components/PlaceStructureComponent.h"

namespace server {
namespace zone {
namespace objects {
namespace tangible {
namespace deed {
namespace components {

class PlaceDecorationComponent : public PlaceStructureComponent {
public:
	int placeStructure(StructureDeed* deed, CreatureObject* creature, float x, float y, int angle) const;

};

} // namespace components
} // namespace deed
} // namespace tangible
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::tangible::deed::components;
