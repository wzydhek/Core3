#include "PackedPosition.h"

PackedPosition::PackedPosition() {
	x = 0;
	y = 0;
	z = 0;
}

PackedPosition::PackedPosition(const Vector3& vector) {
	set(vector);
}

void PackedPosition::parse(Message* message) {
	x = message->readSignedShort();
	z = message->readSignedShort();
	y = message->readSignedShort();
}

void PackedPosition::write(Message* message) {
	message->writeSignedShort(x);
	message->writeSignedShort(z);
	message->writeSignedShort(y);
}

void PackedPosition::set(const Vector3& vector) {
	x = (int16)(Math::clamp(-8000.0f, vector.getX(), 8000.f) * positionScale);
	y = (int16)(Math::clamp(-8000.0f, vector.getY(), 8000.f) * positionScale);
	z = (int16)(Math::clamp(-8000.0f, vector.getZ(), 8000.f) * positionScale);
}

Vector3 PackedPosition::get() {
	return Vector3(x, y, z) * inversePositionScale;
}