/*
 * BoundaryPolygon.h
 *
 *  Created on: 01/02/2010
 *      Author: victor
 */

#pragma once

#if defined (__clang__) && (__clang_major__ >= 18)
	#pragma clang diagnostic push
	#pragma clang diagnostic ignored "-Wnan-infinity-disabled"
#endif

#include "../ProceduralRule.h"
#include "../affectors/AffectorRiver.h"
#include "Boundary.h"
#include "../../ProceduralTerrainAppearance.h"

#include <limits>

class BoundaryPolygon : public Boundary {
	Vector<Point2D*> vertices;
	int localWaterTableEnabled;
	float localWaterTableHeight;
	float shaderSize;
	String shaderName;

	float minX, minY, maxX, maxY;

public:
	const Vector<Point2D*>& getVertices() const;

	BoundaryPolygon();

	~BoundaryPolygon();

	void executeRule(ProceduralTerrainAppearance* generator) final;

	void translateBoundary(float x, float y) final;

	void initialize();

	float checkInfluence(float x, float y) const final;

	float process(float x, float y) const final;

	bool containsPoint(float px, float py) const final;

	void parseFromIffStream(engine::util::IffStream* iffStream) override;

	void parseFromIffStream(engine::util::IffStream* iffStream, Version<'0005'>);

	float getLocalWaterTableHeight() const final;

	float getMinX() const final;

	float getMaxX() const final;

	float getMinY() const final;

	float getMaxY() const final;
};

#if defined (__clang__) && (__clang_major__ >= 18)
	#pragma clang diagnostic pop
#endif
