/*
 * PathEdge.h
 *
 *  Created on: Apr 4, 2015
 *      Author: TheAnswer
 */

#pragma once

#include "engine/util/iffstream/IffStream.h"

namespace templates {
namespace appearance {

class PathEdge {
	int from, to;

	float laneWidthRight;
	float laneWidthLeft;

public:
	PathEdge();

	void readObject(IffStream* iffStream);

	int getFromConnection() const;

	int getToConnection() const;

	float getLaneWidthRight() const;

	float getLaneWidthLeft() const;

	bool toBinaryStream(ObjectOutputStream* stream);

	bool parseFromBinaryStream(ObjectInputStream* stream);
};

} // namespace appearance
} // namespace templates

using namespace templates::appearance;
