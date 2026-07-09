/*
 * StructureFootprint.h
 *
 *  Created on: Apr 30, 2011
 *      Author: crush
 */

#pragma once

#include "templates/IffTemplate.h"

class StructureFootprint : public IffTemplate {
	int rowSize;
	int colSize;

	int centerX;
	int centerY;

	float rowChunkSize;
	float colChunkSize;

	Vector<String> rows;

public:
	StructureFootprint();

	StructureFootprint(const StructureFootprint& sfp);

	StructureFootprint& operator=(const StructureFootprint& sfp);

	void readObject(IffStream* iffStream);

	String toString() const;

	String toStringData() const;

	float getRowSize() const;

	float getColSize() const;

	float getCenterX() const;

	float getCenterY() const;

	float getRowChunkSize() const;

	float getColChunkSize() const;
};
