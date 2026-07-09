/*
 * ChildCreatureObject.h
 *
 *  Created on: Jan 7, 2013
 *      Author: root
 */

#pragma once

#include "system/lang/Object.h"
#include "engine/util/u3d/Vector3.h"
#include "engine/lua/LuaObject.h"

class ChildCreatureObject : public Object {
	Vector3 position;

	int cellid;
	int containmentType;
	String mobileName;
	int respawnTime;
	float heading;

public:
	ChildCreatureObject();

	ChildCreatureObject(const ChildCreatureObject& obj);

	ChildCreatureObject& operator=(const ChildCreatureObject& obj);

	void parseFromLua(LuaObject* luaObject);

	void setPosition(float x, float z, float y);

	void setCellId(int id);

	void setContainmentType(int containment);

	void setMobileName(String name);

	void setRespawnTime(int respawn);

	void setHeading(float head);

	const Vector3& getPosition() const;

	int getCellId() const;

	int getContainmentType() const;

	const String& getMobile() const;

	float getHeading() const;

	int getRespawnTimer() const;
};
