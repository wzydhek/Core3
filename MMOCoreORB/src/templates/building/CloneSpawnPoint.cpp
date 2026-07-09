#include "CloneSpawnPoint.h"

CloneSpawnPoint::CloneSpawnPoint() : cellid(0) {
}

CloneSpawnPoint::CloneSpawnPoint(const CloneSpawnPoint& p) : Object() {
	coordinate.setPositionX(p.getPositionX());
	coordinate.setPositionZ(p.getPositionZ());
	coordinate.setPositionY(p.getPositionY());

	direction.set(p.direction.getW(), p.direction.getZ(), p.direction.getY(), p.direction.getZ());
	cellid = p.cellid;
}

CloneSpawnPoint& CloneSpawnPoint::operator=(const CloneSpawnPoint& p) {
	if (this == &p) {
		return *this;
	}

	coordinate = p.coordinate;
	direction = p.direction;
	cellid = p.cellid;

	return *this;
}

void CloneSpawnPoint::parseFromLua(LuaObject* luaObject) {
	coordinate.setPositionX(luaObject->getFloatField("x"));
	coordinate.setPositionZ(luaObject->getFloatField("z"));
	coordinate.setPositionY(luaObject->getFloatField("y"));

	direction.set(luaObject->getFloatField("ow"), luaObject->getFloatField("ox"), luaObject->getFloatField("oy"), luaObject->getFloatField("oz"));

	cellid = luaObject->getIntField("cellid");
}

float CloneSpawnPoint::getPositionX() const {
	return coordinate.getPositionX();
}

float CloneSpawnPoint::getPositionY() const {
	return coordinate.getPositionY();
}

float CloneSpawnPoint::getPositionZ() const {
	return coordinate.getPositionZ();
}

Coordinate* CloneSpawnPoint::getCoordinate() {
	return &coordinate;
}

Quaternion* CloneSpawnPoint::getDirection() {
	return &direction;
}

int CloneSpawnPoint::getCellID() {
	return cellid;
}