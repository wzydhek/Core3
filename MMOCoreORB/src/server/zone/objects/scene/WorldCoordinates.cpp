/*
 * WorldCoordinate.cpp
 *
 *  Created on: 02/03/2011
 *      Author: victor
 */

#include "WorldCoordinates.h"
#include "server/zone/objects/cell/CellObject.h"

WorldCoordinates::WorldCoordinates() : Object() {
}

WorldCoordinates::WorldCoordinates(const WorldCoordinates& c) : Object() {
	point = c.point;
	cell = c.cell;
}

#ifdef CXX11_COMPILER
WorldCoordinates::WorldCoordinates(WorldCoordinates&& c) : Object(), point(c.point), cell(std::move(c.cell)) {
}
#endif

WorldCoordinates& WorldCoordinates::operator=(const WorldCoordinates& c) {
	if (this == &c) {
		return *this;
	}

	point = c.point;
	cell = c.cell;

	return *this;
}

#ifdef CXX11_COMPILER
WorldCoordinates& WorldCoordinates::operator=(WorldCoordinates&& c) {
	if (this == &c)
		return *this;

	point = c.point;
	cell = std::move(c.cell);

	return *this;
}
#endif

WorldCoordinates::WorldCoordinates(SceneObject* obj) : Object() {
	point = obj->getPosition();

	ManagedReference<CellObject*> parent = obj->getParent().get().castTo<CellObject*>();

	if (parent != nullptr && obj != parent) {
		cell = parent;
	}
}

WorldCoordinates::WorldCoordinates(const Vector3& position, CellObject* parent) : Object() {
	point = position;

	if (parent != nullptr) {
		cell = parent;
	}
}

WorldCoordinates::~WorldCoordinates() {
	cell = nullptr;
}

bool WorldCoordinates::toBinaryStream(ObjectOutputStream* stream) {
	point.toBinaryStream(stream);
	cell.toBinaryStream(stream);

	return true;
}

bool WorldCoordinates::parseFromBinaryStream(ObjectInputStream* stream) {
	point.parseFromBinaryStream(stream);
	cell.parseFromBinaryStream(stream);

	return true;
}

Vector3 WorldCoordinates::getWorldPosition() const {
	if (cell == nullptr) {
		return point;
	}

	SceneObject* root = cell->getRootParent();

	if (root == nullptr) {
		return point;
	}

	float rootRad = -root->getDirection()->getRadians();
	float rootCos = cos(rootRad);
	float rootSin = sin(rootRad);

	float localX = point.getX();
	float localY = point.getY();
	float localZ = point.getZ();

	float rotatedX = (localX * rootCos) - (localY * rootSin);
	float rotatedY = (localX * rootSin) + (localY * rootCos);

	float worldX = root->getPositionX() + rotatedX;
	float worldY = root->getPositionY() + rotatedY;
	float worldZ = root->getPositionZ() + localZ;

	return Vector3(worldX, worldY, worldZ);
}


bool WorldCoordinates::isInRange(const WorldCoordinates& obj, float range) const {
	Vector3 thisWorldPos = getWorldPosition();
	Vector3 objWorldPos = obj.getWorldPosition();

	return thisWorldPos.squaredDistanceTo(objWorldPos) <= (range * range);
}

bool WorldCoordinates::operator==(const WorldCoordinates& c) {
	return (point == c.point) && (cell == c.cell);
}

void to_json(nlohmann::json& j, const WorldCoordinates& c) {
	j["point"] = c.point;
	j["cell"] = c.cell;
}

void WorldCoordinates::setCell(CellObject* obj) {
	cell = obj;
}

void WorldCoordinates::setCoordinates(const Vector3& pos) {
	point = pos;
}

void WorldCoordinates::setX(float x) {
	point.setX(x);
}

void WorldCoordinates::setY(float y) {
	point.setY(y);
}

void WorldCoordinates::setZ(float z) {
	point.setZ(z);
}

const Vector3& WorldCoordinates::getPoint() const {
	return point;
}

Vector3 WorldCoordinates::getPoint() {
	return point;
}

CellObject* WorldCoordinates::getCell() const {
	return cell;
}

float WorldCoordinates::getX() const {
	return point.getX();
}

float WorldCoordinates::getY() const {
	return point.getY();
}

float WorldCoordinates::getZ() const {
	return point.getZ();
}

String WorldCoordinates::toString() const {
	StringBuffer buf;

	buf << "WorldCoordinates(x:" << point.getX() << ", y:" << point.getY() << ", z:" << point.getZ() << ", cell: ";

	if (cell == nullptr) {
		buf << "nullptr";
	} else {
		buf << cell->getCellNumber();
	}

	buf << ")";

	return buf.toString();
}

String WorldCoordinates::toStringData() const {
	return toString();
}