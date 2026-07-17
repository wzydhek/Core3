/*
 * CitizenList.h
 *
 *  Created on: Feb 19, 2012
 *      Author: xyborn
 */

#pragma once

#include "engine/engine.h"
#include "system/util/SynchronizedSortedVector.h"

namespace server {
namespace zone {
namespace objects {
namespace region {

class CitizenList : public SynchronizedSortedVector<uint64> {
public:
	CitizenList();
};

} // namespace region
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::region;
