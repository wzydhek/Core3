/*
 * ValidatedPosition.cpp
 *
 *  Created on: 27/11/2010
 *      Author: victor
 */

#include "ValidatedPosition.h"
#include "server/zone/objects/scene/SceneObject.h"
#include "server/zone/ZoneServer.h"

ValidatedPosition::ValidatedPosition() {
	parent = 0;

	addSerVariables();
}

ValidatedPosition::ValidatedPosition(const Vector3& pos) {
	parent = 0;
	point = pos;

	addSerVariables();
}

ValidatedPosition::ValidatedPosition(const ValidatedPosition& a) : Object(), Serializable() {
	point = a.point;
	parent = a.parent;

	addSerVariables();
}

ValidatedPosition& ValidatedPosition::operator=(const ValidatedPosition& a) {
	point = a.point;
	parent = a.parent;

	return *this;
}

void to_json(nlohmann::json& j, const ValidatedPosition& pos) {
	j["point"] = pos.point;
	j["parent"] = pos.parent;
}

void ValidatedPosition::update(SceneObject* object) {
	point = object->getPosition();

	ManagedReference<SceneObject*> parentPointer = object->getParent().get();

	if (parentPointer != nullptr && (parentPointer->isCellObject() || parentPointer->isValidJtlParent())) {
		parent = parentPointer->getObjectID();
	} else {
		parent = 0;
	}
}

Vector3 ValidatedPosition::getWorldPosition(ZoneServer* zoneServer) {
	if (parent == 0) {
		return point;
	}

	ManagedReference<SceneObject*> newParent = zoneServer->getObject(parent);

	if (newParent == nullptr) {
		return point;
	}

	ManagedReference<SceneObject*> root = newParent->getRootParent();

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

uint64 ValidatedPosition::getParent() const {
	return parent;
}

const Vector3& ValidatedPosition::getPosition() const {
	return point;
}

void ValidatedPosition::setParent(uint64 par) {
	parent = par;
}

void ValidatedPosition::setPosition(const Vector3& pos) {
	point = pos;
}

void ValidatedPosition::setPosition(float x, float z, float y) {
	point.set(x, z, y);
}

void ValidatedPosition::addSerVariables() {
	addSerializableVariable("point", &point);
	addSerializableVariable("parent", &parent);
}