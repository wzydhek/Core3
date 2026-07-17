/*
 * PlaceCityHallComponent.h
 *
 *  Created on: Feb 5, 2012
 *      Author: xyborn
 */

#pragma once

#include "server/zone/objects/tangible/deed/components/PlaceStructureComponent.h"

namespace server {
namespace zone {
namespace objects {
namespace tangible {
namespace deed {
namespace components {

class PlaceCityHallComponent : public PlaceStructureComponent {
public:
	int placeStructure(StructureDeed* deed, CreatureObject* creature, float x, float y, int angle) const;
	int notifyStructurePlaced(StructureDeed* deed, CreatureObject* creature, StructureObject* structure) const;
};

} // namespace components
} // namespace deed
} // namespace tangible
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::tangible::deed::components;
