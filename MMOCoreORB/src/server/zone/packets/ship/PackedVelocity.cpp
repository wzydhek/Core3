#include "PackedVelocity.h"

PackedVelocity::PackedVelocity() : speed(0) {
}

PackedVelocity::PackedVelocity(const Vector3& vector) {
	set(vector);
}

void PackedVelocity::parse(Message* message) {
	speed = message->readSignedShort();
	direction.parse(message);
}

void PackedVelocity::write(Message* message) {
	message->writeShort(speed);

	direction.write(message);
}

void PackedVelocity::set(const Vector3& v) {
	float const mag = v.length();

	speed = static_cast<int16>(clamp(-512.f, mag, 512.f) * velocityScale);

	direction.set(mag ? v / mag : Vector3(0, 0, 1));
}

Vector3 PackedVelocity::get() {
	return direction.get() * speed * inverseVelocityScale;
}

float PackedVelocity::getSpeed() {
	return speed * inverseVelocityScale;
}