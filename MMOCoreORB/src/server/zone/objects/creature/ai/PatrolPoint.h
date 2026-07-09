/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "system/lang.h"
#include "engine/util/json_utils.h"
#include "server/zone/objects/scene/SceneObject.h"
#include "server/zone/objects/cell/CellObject.h"
#include "server/zone/objects/scene/WorldCoordinates.h"

class PatrolPoint : public Serializable {
	WorldCoordinates position;

	bool reached;

	SerializableTime estimatedTimeOfArrival;

	float direction;

public:
	PatrolPoint();

	PatrolPoint(const Vector3& pos, CellObject* cell = nullptr);

	PatrolPoint(float posX, float posZ, float posY, CellObject* cell = nullptr);

	PatrolPoint(const PatrolPoint& point);

#ifdef CXX11_COMPILER
	PatrolPoint(PatrolPoint&& point);
#endif

	PatrolPoint& operator=(const PatrolPoint& p);

#ifdef CXX11_COMPILER
	PatrolPoint& operator=(PatrolPoint&& p);
#endif

	void addSerializableVariables();

	friend void to_json(nlohmann::json& j, const PatrolPoint& p) {
		j["position"] = p.position;
		j["reached"] = p.reached;
		j["direction"] = p.direction;
		j["estimatedTimeOfArrival"] = p.estimatedTimeOfArrival;
	}

	Vector3 getWorldPosition();

	virtual bool isInRange(SceneObject* obj, float range);

	bool isInRange(PatrolPoint* obj, float range);

	const WorldCoordinates& getCoordinates() const;

	//getters
	float getPositionX() const;

	float getPositionY() const;

	float getPositionZ() const;

	CellObject* getCell() const;

	float getDirection() const;

	Time* getEstimatedTimeOfArrival();

	bool isReached() const;

	bool isPastTimeOfArrival();

	//setters
	void setPosition(float x, float z, float y);

	void setPositionX(float x);

	void setPositionZ(float z);

	void setPositionY(float y);

	void setCell(CellObject* cell);

	void setDirection(float dir);

	void setReached(bool value);

	void addEstimatedTimeOfArrival(uint32 mili);

	/**
	 * Returns the string representation of the vector in (x, y, z) format plus the cellID.
	 */
	String toString() const;
};
