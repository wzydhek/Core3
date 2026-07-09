/*
 * BoundaryRectangle.h
 *
 *  Created on: 01/02/2010
 *      Author: victor
 */

#pragma once

#include "../ProceduralRule.h"
#include "Boundary.h"
#include "../../ProceduralTerrainAppearance.h"

class BoundaryRectangle : public Boundary {
	float x0;
	float y0;
	float x1;
	float y1;

	int var7;
	int localWaterTableEnabled;
	float localWaterTableHeight;
	float shaderSize;
	String shaderName;

	float newX0, newX1, newY0, newY1;

    /*
     * result of process() is modified based on this feathering types and then multiplied by the affectors
     * feathering types:
     * 1: x^2
     * 2: sqrt(x)
     * 3: x^2 * (3 - 2x)
     */

public:
	BoundaryRectangle();

	BoundaryRectangle(float x0, float y0, float x1, float y1);

	~BoundaryRectangle();

	void executeRule(ProceduralTerrainAppearance* generator) final;

	bool containsPoint(float X, float Y) const final;

	void parseFromIffStream(engine::util::IffStream* iffStream) final;

	void parseFromIffStream(engine::util::IffStream* iffStream, Version<'0002'>);

	void parseFromIffStream(engine::util::IffStream* iffStream, Version<'0003'>);

	float getLocalWaterTableHeight() const final;

	float checkInfluence(float x, float y) const final;

	float process(float x, float y) const final;

	void translateBoundary(float x, float y);

	void initialize();

	float getMinX() const final;

	float getMaxX() const final;

	float getMinY() const final;

	float getMaxY() const final;
};
