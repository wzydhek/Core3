/*
 * Segment.h
 *
 *  Created on: 31/01/2010
 *  Author: victor
 */

#pragma once

#include "../TemplateVariable.h"

namespace terrain {
namespace layer {

class Point3D {
public:
	float x, z, y;

	Point3D();

	Point3D(float newX, float newY, float newZ);

	float squaredDistanceTo(float locX, float locZ, float locY);

	float squaredDistanceTo(float locX, float locY);

	float getX();

	float getZ();

	float getY();
};

// #define DEBUG_AFFECTOR_ROAD

class Segment : public TemplateVariable<'SGMT'> {
	Vector<Point3D*> positions;
	bool flatRoad;

public:
	Segment();

	~Segment();

	void createRoadwayHeights();
	void readObject(engine::util::IffStream* iffStream);
	bool hasInitialCoordinate(float x, float y);
	void findNearestHeight(float& baseValue, Vector3 worldPosition, Vector3 roadCenter, float direction);

	void setFlatRoad(bool val);

	bool isFlatRoad();
};

} // namespace layer
} // namespace terrain

using namespace terrain::layer;
