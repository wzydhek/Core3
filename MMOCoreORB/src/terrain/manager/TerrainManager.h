/*
 * TerrainManager.h
 *
 *  Created on: 31/01/2010
 *      Author: victor
 */

#pragma once

#include "terrain/TerrainAppearance.h"

#ifdef COMPILE_CORE3_TESTS
	#include "gmock/gmock.h"
#endif

#include "TerrainCache.h"

class ProceduralTerrainAppearance;

class TerrainManager : public Logger, public Object {
	Reference<TerrainAppearance*> terrainData;

	TerrainCache* heightCache;

	float min, max;

protected:
	void clearCache(TerrainGenerator* generator);

public:
	TerrainManager();
	~TerrainManager();

	bool initialize(const String& terrainFile);

	bool getWaterHeight(float x, float y, float& waterHeight) const;

	/**
	 *  	|----------------| x1,y1
	 *  	|----------------| <- stepping
	 *		|----------------|
	 *  	|----------------|
	 *x0,y0 |----------------|
	 */
	float getHighestHeight(float x0, float y0, float x1, float y1, int stepping = 1);
	float getLowestHeight(float x0, float y0, float x1, float y1, int stepping = 1);
	float getHighestHeightDifference(float x0, float y0, float x1, float y1, int stepping = 1);

	void addTerrainModification(float x, float y, const String& terrainModificationFilename, uint64 objectid);
	void removeTerrainModification(uint64 objectid);

	ProceduralTerrainAppearance* getProceduralTerrainAppearance();

	float getCachedHeight(float x, float y);
	float getUnCachedHeight(float x, float y) const;

	virtual float getHeight(float x, float y);

	float getMin() const;

	float getMax() const;

	float getSize() const;

	int getCacheHitCount() const;

	int getCacheMissCount() const;

	int getCacheClearCount() const;

	int getCacheClearHeightsCount() const;

	int getCachedValuesCount() const;

	int getCacheEvictCount() const;
};

#ifdef COMPILE_CORE3_TESTS
	class MockTerrainManager : public TerrainManager {
	public:
		MOCK_METHOD2(getHeight,float(float x, float y));
	};
#endif
