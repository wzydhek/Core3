#pragma once

namespace server {
	namespace zone {
		namespace objects {
			namespace ship {
				class ShipObject;
			}
		}
	}
}

#include "engine/engine.h"
#include "server/zone/objects/tangible/TangibleObject.h"

class SpaceTransformType : public Object {
public:
	enum Type : int {
		NONE = -1,
		SLOW = 0,
		AUTO = 1,
		FAST = 2,
		DOCK = 3,
		FORM = 4,
		SIZE
	};

	enum Rotation : int {
		YAW = 0,
		PITCH = 1,
		ROLL = 2
	};

	constexpr static float DAMP_RADIUS_MAX = 128.f;
	constexpr static float DAMP_RADIUS_MIN = 32.f;

protected:
	Vector3 rotationDamp;
	Vector3 rotationRate;

	float throttleMin;
	float throttleMax;

	int transformType;

public:
	SpaceTransformType();

	SpaceTransformType(ShipObject* ship, int type = AUTO);

	void initializeType(ShipObject* ship, int type = AUTO);

	void setTransformType(int type);

	const Vector3& getRotationRate() const;

	float getThrottleMin() const;

	float getThrottleMid() const;

	float getThrottleMax() const;

	int getTransformType() const;

private:
	void setThrottleRate();

	void setRotationRate();

	void setRotationDamp(float radius);

public:
	String toDebugString(bool includePrivate = false) const;
};
