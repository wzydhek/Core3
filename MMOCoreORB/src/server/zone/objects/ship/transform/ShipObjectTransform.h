#pragma once


#include "engine/engine.h"
#include "server/zone/objects/tangible/TangibleObject.h"
#include "server/zone/objects/ship/transform/SpaceMath.h"
#include "server/zone/objects/ship/transform/SpaceTransform.h"
#include "server/zone/objects/ship/transform/SpaceTransformType.h"
namespace server {
namespace zone {
namespace objects {
namespace ship {
class ShipObject;
namespace transform {

class ShipObjectTransform : public Object {
public:
	constexpr static float VELOCITY_MAX = 512.f;
	constexpr static float DELTA_MAX = 0.5f;
	constexpr static float DELTA_MIN = 0.1f;

	constexpr static float POSITION_EPSILON = 0.25f;
	constexpr static float ROTATION_EPSILON = 0.25f * (M_PI / 180.0f);

private:
	mutable ReadWriteLock mutex;
	uint64 serverTime;
	float deltaTime;

protected:
	SpaceTransform previousTransform;
	SpaceTransform currentTransform;
	SpaceTransform nextTransform;

	SpaceTransformType transformType;
	float nextDistance;
	float nextRotation;

public:
	ShipObjectTransform();

	ShipObjectTransform(ShipObject* ship);

	void initializeTransform(ShipObject* ship);

	void setCurrentTransform(ShipObject* ship);

	void setNextTransform(const Vector3& position, float speed = VELOCITY_MAX, int model = SpaceTransformType::AUTO);

	void setNextTransform(const SpaceTransform& transform, int model = SpaceTransformType::AUTO);

	void freezeRotation();

	void updateTransform(ShipObject* ship, bool lightUpdate = false, bool notifyClient = true);

	void broadcastTransform(ShipObject* ship);

	const SpaceTransform& getPreviousTransform() const;

	const SpaceTransform& getCurrentTransform() const;

	const SpaceTransform& getNextTransform() const;

	float getNextDistance() const;

	float getNextRotation() const;

private:
	void setTransform(ShipObject* ship);

	void setSpeed(ShipObject* ship);

	void setRotation(ShipObject* ship);

	void setPosition(ShipObject* ship);

	void setVelocity(ShipObject* ship);

	void updateCurrentTransform(ShipObject* ship);

	void updateNextTransform(ShipObject* ship);

	void updateShip(ShipObject* ship);

	void setDeltaTime();

	bool isScheduled() const;

	bool isStaticUpdate() const;

	bool isInertiaUpdate() const;

public:
	String toDebugString() const;
};

} // namespace transform
} // namespace ship
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::ship::transform;
