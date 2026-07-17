/*
 * BoundaryPolyline.h
 *
 *  Created on: 01/02/2010
 *      Author: victor
 */

#pragma once

#include "../ProceduralRule.h"
#include "../affectors/AffectorRiver.h"
#include "Boundary.h"

namespace terrain {
namespace layer {
namespace boundaries {

class BoundaryPolyline : public Boundary {
	Vector<Point2D*> points;
	float lineWidth;

	float minX, minY, maxX, maxY;

public:
	BoundaryPolyline();

	~BoundaryPolyline();

	void parseFromIffStream(engine::util::IffStream* iffStream) override;

	float checkInfluence(float x, float y) const final;

	void parseFromIffStream(engine::util::IffStream* iffStream, Version<'0001'>);

	void translateBoundary(float x, float y) final;

	void initialize();

	bool containsPoint(float x, float y) const final;

	float process(float x, float y) const final;

	float getMinX() const final;

	float getMaxX() const final;

	float getMinY() const final;

	float getMaxY() const final;

};

} // namespace boundaries
} // namespace layer
} // namespace terrain

using namespace terrain::layer::boundaries;
