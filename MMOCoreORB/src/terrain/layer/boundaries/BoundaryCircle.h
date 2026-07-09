/*
 * BoundaryCircle.h
 *
 *  Created on: 01/02/2010
 *      Author: victor
 */

#pragma once

#include "../ProceduralRule.h"
#include "Boundary.h"

class BoundaryCircle : public Boundary {
	float centerX;
	float centerY;
	float radius;
	float radiusSquared;

public:
	BoundaryCircle();

	void parseFromIffStream(engine::util::IffStream* iffStream) final;

	void parseFromIffStream(engine::util::IffStream* iffStream, Version<'0002'>);

	float checkInfluence(float x, float y) const final;

	bool containsPoint(float x, float y) const final;

	float process(float x, float y) const final;

	void translateBoundary(float x, float y) final;

	float getMinX() const final;

	float getMaxX() const final;

	float getMinY() const final;

	float getMaxY() const final;
};
