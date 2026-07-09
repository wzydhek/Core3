#pragma once

#include "engine/engine.h"

class SpaceTransform : public Object {
protected:
	Vector3 position;
	Vector3 rotation;
	Vector3 yprDelta;
	Vector3 velocity;
	float speed;

public:
	SpaceTransform();

	void setPosition(const Vector3& value);

	void setRotation(const Vector3& value);

	void setYprDelta(const Vector3& value);

	void setVelocity(const Vector3& value);

	void setSpeed(float value);

	const Vector3& getPosition() const;

	const Vector3& getRotation() const;

	const Vector3& getYprDelta() const;

	const Vector3& getVelocity() const;

	float getSpeed() const;

	String toDebugString() const;
};
