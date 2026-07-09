#include "ChildCreatureObject.h"

ChildCreatureObject::ChildCreatureObject() {
	cellid = 0;
	containmentType = 0;
	respawnTime = 0;
	heading = 0;
}

ChildCreatureObject::ChildCreatureObject(const ChildCreatureObject& obj) : Object() {
	position = obj.position;
	cellid = obj.cellid;
	containmentType = obj.containmentType;
	mobileName = obj.mobileName;
	respawnTime = obj.respawnTime;
	heading = obj.heading;
}

ChildCreatureObject& ChildCreatureObject::operator=(const ChildCreatureObject& obj) {
	if (this == &obj)
		return *this;

	position = obj.position;
	cellid = obj.cellid;
	containmentType = obj.containmentType;
	mobileName = obj.mobileName;
	respawnTime = obj.respawnTime;
	heading = obj.heading;

	return *this;
}

void ChildCreatureObject::parseFromLua(LuaObject* luaObject) {
	position.setX(luaObject->getFloatField("x"));
	position.setZ(luaObject->getFloatField("z"));
	position.setY(luaObject->getFloatField("y"));
	cellid = luaObject->getIntField("cellid");
	containmentType = luaObject->getIntField("containmentType");
	mobileName = luaObject->getStringField("mobile");
	respawnTime = luaObject->getIntField("respawn");
	heading = luaObject->getFloatField("heading");
}

void ChildCreatureObject::setPosition(float x, float z, float y) {
	position.set(x, z, y);
}

void ChildCreatureObject::setCellId(int id) {
	cellid = id;
}

void ChildCreatureObject::setContainmentType(int containment) {
	containmentType = containment;
}

void ChildCreatureObject::setMobileName(String name) {
	mobileName = name;
}

void ChildCreatureObject::setRespawnTime(int respawn) {
	respawnTime = respawn;
}

void ChildCreatureObject::setHeading(float head) {
	heading = head;
}

const Vector3& ChildCreatureObject::getPosition() const {
	return position;
}

int ChildCreatureObject::getCellId() const {
	return cellid;
}

int ChildCreatureObject::getContainmentType() const {
	return containmentType;
}

const String& ChildCreatureObject::getMobile() const {
	return mobileName;
}

float ChildCreatureObject::getHeading() const {
	return heading;
}

int ChildCreatureObject::getRespawnTimer() const {
	return respawnTime;
}