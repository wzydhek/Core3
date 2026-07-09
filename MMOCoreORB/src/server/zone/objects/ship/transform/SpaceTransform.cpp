#include "SpaceTransform.h"

SpaceTransform::SpaceTransform() : Object() {
	speed = 0.f;
}

void SpaceTransform::setPosition(const Vector3& value) {
	position = value;
}

void SpaceTransform::setRotation(const Vector3& value) {
	rotation = value;
}

void SpaceTransform::setYprDelta(const Vector3& value) {
	yprDelta = value;
}

void SpaceTransform::setVelocity(const Vector3& value) {
	velocity = value;
}

void SpaceTransform::setSpeed(float value) {
	speed = value;
}

const Vector3& SpaceTransform::getPosition() const {
	return position;
}

const Vector3& SpaceTransform::getRotation() const {
	return rotation;
}

const Vector3& SpaceTransform::getYprDelta() const {
	return yprDelta;
}

const Vector3& SpaceTransform::getVelocity() const {
	return velocity;
}

float SpaceTransform::getSpeed() const {
	return speed;
}

String SpaceTransform::toDebugString() const {
	StringBuffer msg;
	msg << "SpaceTransform: " << endl << "  position: " << position.toString() << endl << "  rotation: " << rotation.toString() << endl << "  yprDelta: " << yprDelta.toString() << endl << "  velocity: " << velocity.toString() << endl << "  speed:    " << speed;

	return msg.toString();
}