/*
 * PackedVelocity.h
 *
 *  Created on: Apr 4, 2015
 *      Author: TheAnswer
 */

#pragma once

#include "PackedUnitVector.h"

namespace server {
namespace zone {
namespace packets {
namespace ship {

class PackedVelocity {
protected:
	const static constexpr float velocityScale = 32767.f / 512.f;
	const static constexpr float inverseVelocityScale = 512.f / 32767.f;

	int16 speed;
	PackedUnitVector direction;

public:
	PackedVelocity();

	PackedVelocity(const Vector3& vector);

	void parse(Message* message);

	void write(Message* message);

	void set(const Vector3& v);

	Vector3 get();

	float getSpeed();
};

} // namespace ship
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::ship;
