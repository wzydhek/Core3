/*
 * PackedUnitVector.h
 *
 *  Created on: Apr 4, 2015
 *      Author: TheAnswer
 */

#pragma once

#include "engine/util/u3d/Vector3.h"
#include "engine/service/proto/BaseMessage.h"

template<class T>inline const T clamp(const T &minT, const T &t, const T &maxT) {
	return (t < minT) ? minT : ((t > maxT) ? maxT : t);
}

class PackedUnitVector {
	enum
	{
		packedSize = 2,
		xSignMask = 0x8000u,
		ySignMask = 0x4000u,
		zSignMask = 0x2000u,
		componentMask = 0x003fu,
		componentMaskBits = 6
	};

	uint16 value;

public:
	PackedUnitVector();

	PackedUnitVector(const Vector3& vector);

	void parse(Message* message);

	void write(Message* message);

	void set(const Vector3& v);

	Vector3 get();
};
