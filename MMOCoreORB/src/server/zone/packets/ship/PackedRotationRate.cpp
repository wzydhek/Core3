#include "PackedRotationRate.h"

PackedRotationRate::PackedRotationRate() : rate(0) {
}

PackedRotationRate::PackedRotationRate(float value) {
	set(value);
}

void PackedRotationRate::set(float value) {
	rate = static_cast<int8>(Math::clamp(-(PI_2), value, (PI_2)) * (127.f / PI_2));
}

float PackedRotationRate::get() {
	return rate * ((PI_2) / 127.f);
}

void PackedRotationRate::parse(Message* message) {
	rate = message->readSignedByte();
}

void PackedRotationRate::write(Message* message) {
	message->writeSignedByte(rate);
}