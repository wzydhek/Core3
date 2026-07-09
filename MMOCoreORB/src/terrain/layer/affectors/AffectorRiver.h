/*
 * AffectorRiver.h
 *
 *  Created on: 31/01/2010
 *      Author: victor
 */

#pragma once

#include "../ProceduralRule.h"
#include "AffectorProceduralRule.h"
#include "../Road.h"
#include "../HeightData.h"

class Point2D  {
public:
	float x, y;

	Point2D();

	Point2D(float xPos, float yPos);

	float getX() const;

	float getY() const;
};

class AffectorRiver : public ProceduralRule<'ARIV'>, public AffectorProceduralRule {
	Road road;
	HeightData hdta;

	int var1;

	Vector<Point2D*> positions;

	float var2;
	int var3;
	int var4;
	int var5;
	float var6;
	float var7;
	float var8;
	int var9;
	float var10;
	float var11;
	float var12;

	String var15;

public:
	AffectorRiver();

	~AffectorRiver();

	void parseFromIffStream(engine::util::IffStream* iffStream);

	void parseFromIffStream(engine::util::IffStream* iffStream, Version<'0005'>);
};
