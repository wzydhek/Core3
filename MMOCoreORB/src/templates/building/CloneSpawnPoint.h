/*
 * CloneSpawnPoint.h
 *
 *  Created on: 23/06/2010
 *      Author: victor
 */

#pragma once

#include "engine/util/u3d/Coordinate.h"
#include "engine/util/u3d/Quaternion.h"
#include "engine/lua/LuaObject.h"

namespace templates {
namespace building {

class CloneSpawnPoint : public Object {
	Coordinate coordinate;
	Quaternion direction;
	int cellid;
public:
	CloneSpawnPoint();

	CloneSpawnPoint(const CloneSpawnPoint& p);

	CloneSpawnPoint& operator=(const CloneSpawnPoint& p);

	void parseFromLua(LuaObject* luaObject);

	float getPositionX() const;

	float getPositionY() const;

	float getPositionZ() const;

	Coordinate* getCoordinate();

	Quaternion* getDirection();

	int getCellID();
};

} // namespace building
} // namespace templates

using namespace templates::building;
