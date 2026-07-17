/*
 * PackedPosition.h
 *
 *  Created on: Aug 22, 2017
 *	  Author: TheAnswer
 */

#pragma once

#include "engine/engine.h"
#include "PackedUnitVector.h"
#include "engine/service/proto/BaseMessage.h"

namespace server {
namespace zone {
namespace packets {
namespace ship {

class PackedPosition {
public:
	static const constexpr float positionScale = 32767.f / 8000.f;
	static const constexpr float inversePositionScale = 8000.f / 32767.f;

protected:
	int16 x;
	int16 y;
	int16 z;

public:
	PackedPosition();

	PackedPosition(const Vector3& vector);

	void parse(Message* message);

	void write(Message* message);

	void set(const Vector3& vector);

	Vector3 get();
};

} // namespace ship
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::ship;
