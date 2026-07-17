/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

/**
 * \file SpawnMap.h
 * \author Kyle Burkhardt
 * \date 5-03-10
 */

#pragma once

#include "engine/engine.h"
#include "SpawnDensityMap.h"

namespace server {
namespace zone {
namespace objects {
namespace resource {

class SpawnMap : public SynchronizedVectorMap<String, SpawnDensityMap> {

public:
	SpawnMap();

	~SpawnMap();

};

} // namespace resource
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::resource;
