/*
 * AffectorRoad.h
 *
 *  Created on: 01/02/2010
 *      Author: victor
 */

#pragma once

#include "../ProceduralRule.h"
#include "../Road.h"
#include "../HeightData.h"
#include "../../TerrainGenerator.h"
#include "AffectorRiver.h"

namespace terrain {

class TerrainGenerator;

} // namespace affectors

using namespace terrain;

namespace terrain {
namespace layer {
namespace affectors {

// #define DEBUG_AFFECTOR_ROAD

class RoadRectangle {
	float lowerLeftX, lowerLeftY, upperRightX, upperRightY;
	float roadStartX, roadStartY, centerX, centerY;
	float width, height, direction;

public:
	RoadRectangle(float x0, float y0, float x1, float y1, float startX, float startY, float roadWidth, float dir);

	~RoadRectangle();

	bool containsPoint(float x, float y) const;

	float getLowerLeftX() const;

	float getLowerLeftY() const;

	float getUpperRightX() const;

	float getUpperRightY() const;

	float getRoadStartX();

	float getRoadStartY();

	float getRoadCenterX();

	float getRoadCenterY();

	float getDirection();
};

class AffectorRoad : public ProceduralRule<'AROA'>, public AffectorProceduralRule {
	Road road;
	HeightData hdta;

	uint32 type;
	int coordinateCount;

	Point2D startPoint;
	Point2D endPoint;
	Vector<Point2D*> midPositions;

	Vector<RoadRectangle*> rectangles;

	float width;
	int familyID;

	int featheringType;
	float featheringAmount;
	int featheringShader;
	float featheringShaderDistance;

	static const int OUT_OF_RANGE = 500;

public:
	AffectorRoad();

	~AffectorRoad();

	void process(float x, float y, float transformValue, float& baseValue, TerrainGenerator* terrainGenerator);

	void parseFromIffStream(engine::util::IffStream* iffStream);
	void parseFromIffStream(engine::util::IffStream* iffStream, Version<'0005'>);
	void addNewRectangle(float x1, float y1, float x2, float y2);
	void generateRectangles();
	void sendDebugMessage(String message);

	int getFamilyID();

	bool isEnabled();
};

} // namespace affectors
} // namespace layer
} // namespace terrain

using namespace terrain::layer::affectors;
