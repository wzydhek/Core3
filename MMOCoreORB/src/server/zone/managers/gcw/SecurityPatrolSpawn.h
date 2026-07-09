#pragma once

#include "system/lang/Object.h"
#include "engine/util/u3d/Vector3.h"
#include "engine/lua/LuaObject.h"

class SecurityPatrolSpawn : public Object {
protected:
	String patrol;
	int faction;
	Vector3 location;
	float direction;

public:
	SecurityPatrolSpawn();

	SecurityPatrolSpawn(const SecurityPatrolSpawn& obj);

	SecurityPatrolSpawn& operator=(const SecurityPatrolSpawn& obj);

	void parseFromLua(LuaObject* luaObject);

	void setlocation(float x, float z, float y);

	void setPatrol(String pat);

	const Vector3& getLocation() const;

	float getDirection() const;

	String getPatrol() const;

	int getFaction() const;
};
