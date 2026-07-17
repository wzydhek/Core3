#pragma once

#include "engine/engine.h"
#include "server/zone/objects/ship/ai/SpacePatrolPoint.h"

namespace server {
namespace zone {
namespace objects {
namespace ship {
namespace ai {
namespace events {

class ShipAiPatrolPathFinder {
public:
	enum PathShape: uint32 {
		CIRCLE = 0,
		SPHERE = 1
	};

	static Vector3 getRandomPosition(const Vector3& position, float radiusMin = 0.f, float radiusMax = 1.f);

	static Vector<SpacePatrolPoint> generatePatrolCircle(const Sphere& sphere, const Matrix4& rotation, int totalPoints);

	static Vector<SpacePatrolPoint> generatePatrolSphere(const Sphere& sphere, const Matrix4& rotation, int totalPoints);
};

} // namespace events
} // namespace ai
} // namespace ship
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::ship::ai::events;
