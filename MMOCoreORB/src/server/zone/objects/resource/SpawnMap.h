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


class SpawnMap : public SynchronizedVectorMap<String, SpawnDensityMap> {

public:
	SpawnMap();

	~SpawnMap();

};
