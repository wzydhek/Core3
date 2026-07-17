/*
 * PackedRotationRate.h
 *
 *  Created on: Apr 4, 2015
 *      Author: TheAnswer
 */

#pragma once

#include "engine/engine.h"
#include "engine/service/proto/BaseMessage.h"

namespace server {
namespace zone {
namespace packets {
namespace ship {

float const PI_2 = 3.14159265358979323846f / 2.f;

class PackedRotationRate {
	enum
	{
		packedSize = 1
	};

	int8 rate;
public:
	PackedRotationRate();

	PackedRotationRate(float value);

	void set(float value);

	float get();

	void parse(Message* message);

	void write(Message* message);
};

} // namespace ship
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::ship;
