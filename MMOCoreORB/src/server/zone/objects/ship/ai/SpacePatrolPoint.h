/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.
*/

#pragma once

#include "system/lang.h"
#include "engine/util/json_utils.h"
#include "server/zone/objects/scene/SceneObject.h"
#include "server/zone/objects/scene/WorldCoordinates.h"

namespace server {
namespace zone {
namespace objects {
namespace ship {
namespace ai {

class SpacePatrolPoint : public Serializable {
	WorldCoordinates position;

	bool reached;
	bool evadePoint;

	SerializableTime estimatedTimeOfArrival;

	Quaternion direction;

public:
	SpacePatrolPoint();

	SpacePatrolPoint(const Vector3& pos);

	SpacePatrolPoint(const SpacePatrolPoint& point);

#ifdef CXX11_COMPILER
	SpacePatrolPoint(SpacePatrolPoint&& point);
#endif

	SpacePatrolPoint& operator=(const SpacePatrolPoint& p);

#ifdef CXX11_COMPILER
	SpacePatrolPoint& operator=(SpacePatrolPoint&& p);
#endif

	bool operator!=(const Vector3& location) const;

	void addSerializableVariables();

	friend void to_json(nlohmann::json& j, const SpacePatrolPoint& p);

	Vector3 getWorldPosition();

	virtual bool isInRange(SceneObject* obj, float range);

	bool isInRange(SpacePatrolPoint* obj, float range);

	const WorldCoordinates& getCoordinates() const;

	//getters
	float getPositionX() const;

	float getPositionY() const;

	float getPositionZ() const;

	Quaternion getDirection() const;

	Time* getEstimatedTimeOfArrival();

	bool isReached() const;

	bool isEvadePoint() const;

	bool isPastTimeOfArrival();

	//setters
	void setPosition(float x, float z, float y);

	void setPositionX(float x);

	void setPositionZ(float z);

	void setPositionY(float y);

	void setCell(CellObject* cell);

	void setDirection(float fw, float fx, float fy, float fz);

	void setReached(bool value);

	void setEvadePoint(bool value);

	void addEstimatedTimeOfArrival(uint32 mili);

	/**
	 * Returns the string representation of the vector in (x, y, z) format plus the cellID.
	 */
	String toString() const;
};

} // namespace ai
} // namespace ship
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::ship::ai;
