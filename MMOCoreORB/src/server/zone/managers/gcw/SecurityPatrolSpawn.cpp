#include "SecurityPatrolSpawn.h"

SecurityPatrolSpawn::SecurityPatrolSpawn() {
	patrol = "";
	faction = 0;
	direction = 0.f;
}

SecurityPatrolSpawn::SecurityPatrolSpawn(const SecurityPatrolSpawn& obj) : Object() {
	patrol = obj.patrol;
	faction = obj.faction;
	location = obj.location;
	direction = obj.direction;
}

SecurityPatrolSpawn& SecurityPatrolSpawn::operator=(const SecurityPatrolSpawn& obj) {
	if (this == &obj)
		return *this;

	patrol = obj.patrol;
	faction = obj.faction;
	location = obj.location;
	direction = obj.direction;

	return *this;
}

void SecurityPatrolSpawn::parseFromLua(LuaObject* luaObject) {
	patrol = luaObject->getStringField("patrol");

	location.setX(luaObject->getFloatField("x"));
	location.setZ(luaObject->getFloatField("z"));
	location.setY(luaObject->getFloatField("y"));

	direction = luaObject->getFloatField("heading");
}

void SecurityPatrolSpawn::setlocation(float x, float z, float y) {
	location.set(x, z, y);
}

void SecurityPatrolSpawn::setPatrol(String pat) {
	patrol = pat;
}

const Vector3& SecurityPatrolSpawn::getLocation() const {
	return location;
}

float SecurityPatrolSpawn::getDirection() const {
	return direction;
}

String SecurityPatrolSpawn::getPatrol() const {
	return patrol;
}

int SecurityPatrolSpawn::getFaction() const {
	return faction;
}