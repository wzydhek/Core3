/*
 * ForageMap.h
 *
 *  Created on: 2/24/2011
 *      Author: Anakis
 */

#pragma once

#include "engine/engine.h"
#include "ForageAreaCollection.h"

namespace server {
namespace zone {
namespace objects {
namespace area {

class ForageMap : public VectorMap<String, Reference<ForageAreaCollection*> > {

};

} // namespace area
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::area;
