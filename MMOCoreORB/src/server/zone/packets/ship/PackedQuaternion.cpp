#include "PackedQuaternion.h"

PackedQuaternion::PackedQuaternion() {
	w = 127;
	x = 0;
	y = 0;
	z = 0;
}

PackedQuaternion::PackedQuaternion(const Quaternion& value) {
	set(value);
}

void PackedQuaternion::set(const Quaternion& value) {
	w = Math::clamp(-1.f, value.getW(), 1.f) * directionScale;
	x = Math::clamp(-1.f, value.getX(), 1.f) * directionScale;
	y = Math::clamp(-1.f, value.getY(), 1.f) * directionScale;
	z = Math::clamp(-1.f, value.getZ(), 1.f) * directionScale;
}

void PackedQuaternion::parse(Message* message) {
	w = message->readSignedByte();
	x = message->readSignedByte();
	y = message->readSignedByte();
	z = message->readSignedByte();
}

void PackedQuaternion::write(Message* message) const {
	message->writeSignedByte(w);
	message->writeSignedByte(x);
	message->writeSignedByte(y);
	message->writeSignedByte(z);
}

Quaternion PackedQuaternion::get() const {
	return Quaternion(w * directionScaleInv, x * directionScaleInv, y * directionScaleInv, z * directionScaleInv);
}