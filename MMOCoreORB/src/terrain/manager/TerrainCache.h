/*
 * TerrainCache.h
 *
 *  Created on: Aug 11, 2015
 *      Author: TheAnswer
 */

#pragma once

#include "engine/engine.h"
#include "engine/util/lru/SynchronizedLRUCache.h"
#include "engine/util/u3d/BasicQuadTree.h"
#include "system/lang/Pair.h"

class TerrainManager;
class TerrainGenerator;

class TerrainCache : public SynchronizedLRUCache2<uint64, float, float,
	Pair<QuadTreeEntryInterface*, float> >, public Logger {
public:
	typedef Pair<QuadTreeEntryInterface*, float> lru_value_t;
	typedef SynchronizedLRUCache2<uint64, float, float, lru_value_t > lru_cache_t;

protected:
	BasicQuadTree quadTree;

	int clearCount;
	int clearHeightsCount;
	int evictCount;

	const float max, min;

public:
	TerrainCache(TerrainManager* terrainManager);
	~TerrainCache();

private:
	bool insert(const float& k, const float& k2, const lru_value_t& v) override;

	lru_value_t evict() override;

public:
	void clear(TerrainGenerator* layers);

	float getHeight(float x, float y);

	int getClearCount() const;

	int getClearHeightsCount() const;

	int getEvictCount() const;
};
