#include "PackedUnitVector.h"

PackedUnitVector::PackedUnitVector() : value(0) {
}

PackedUnitVector::PackedUnitVector(const Vector3& vector) {
	set(vector);
}

void PackedUnitVector::parse(Message* message) {
	value = message->readShort();
}

void PackedUnitVector::write(Message* message) {
	message->writeShort(value);
}

void PackedUnitVector::set(const Vector3& v) {
	value = 0;
	float x = v.getX();

	if (x < 0.f) {
		x = -x;
		value |= xSignMask;
	}

	float y = v.getY();

	if (y < 0.f) {
		y = -y;
		value |= ySignMask;
	}

	float z = v.getZ();

	if (z < 0.f) {
		z = -z;
		value |= zSignMask;
	}

	float const w = static_cast<float>(componentMask - 1) / (x + y + z);
	value |= static_cast<uint16>(x * w) << componentMaskBits;
	value |= static_cast<uint16>(y * w);
}

Vector3 PackedUnitVector::get() {
	float x = static_cast<float>((value >> componentMaskBits) & componentMask);
	float y = static_cast<float>(value & componentMask);
	float z = static_cast<float>(componentMask) - x - y;

	if (value & xSignMask)
		x = -x;

	if (value & ySignMask)
		y = -y;

	if (value & zSignMask)
		z = -z;

	Vector3 v(x, y, z);
	v.normalize();

	return v;
}