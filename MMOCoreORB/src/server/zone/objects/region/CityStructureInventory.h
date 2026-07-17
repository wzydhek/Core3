/*
 * CityStructureInventory.h
 *
 *  Created on: 17/04/2012
 *      Author: victor
 */

#pragma once

#include "engine/engine.h"

namespace server {
namespace zone {
namespace objects {
namespace scene {
class SceneObject;
}
using namespace server::zone::objects::scene;

namespace region {

class CityStructureInventory : public VectorMap<byte, SortedVector<ManagedReference<SceneObject* > > > {

};

} // namespace region
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::region;
