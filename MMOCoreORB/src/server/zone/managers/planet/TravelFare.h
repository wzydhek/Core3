/*
 * TravelFare.h
 *
 *  Created on: April 9, 2012
 *      Author: Itac
 */

#pragma once

#include "system/util/VectorMap.h"
#include "system/lang/String.h"

namespace server {
namespace zone {
namespace managers {
namespace planet {

class TravelFare : public VectorMap<String, VectorMap<String, int> > {

};

} // namespace planet
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::planet;
