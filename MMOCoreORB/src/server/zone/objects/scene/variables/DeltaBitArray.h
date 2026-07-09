/*
 * DeltaBitArray.h
 *
 *  Created on: 15/11/2013
 *      Author: victor
 */

#pragma once

#include "DeltaVector.h"
#include "engine/engine.h"

class DeltaBitArray : public DeltaVector<byte> {
public:
	DeltaBitArray();

	DeltaBitArray(int initsize, int incr);

	DeltaBitArray(const DeltaBitArray& v);

	DeltaBitArray& operator=(const DeltaBitArray& v);

	void setBit(uint32 bitIndex, byte value);

	bool getBitValue(uint32 bitIndex) const;

	void clearBit(int bitIndex);

	int bitCount() const;
};
