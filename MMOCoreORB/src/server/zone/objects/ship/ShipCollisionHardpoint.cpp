#include "ShipCollisionHardpoint.h"
#include "templates/appearance/AppearanceTemplate.h"
#include "ComponentSlots.h"

ShipCollisionHardpoint::ShipCollisionHardpoint() {
	appearance = nullptr;
	rotation = nullptr;

	volumeType = -1;
	radius = -1.f;
	slot = -1;

	targetable = false;
}

ShipCollisionHardpoint::ShipCollisionHardpoint(const String& componentNameValue, const String& hardpointNameValue) : ShipCollisionHardpoint() {
	componentName = componentNameValue;
	hardpointName = hardpointNameValue;
}

void ShipCollisionHardpoint::setAppearanceTemplate(const AppearanceTemplate* value) {
	appearance = value;
}

void ShipCollisionHardpoint::setComponentName(const String& value) {
	componentName = value;
}

void ShipCollisionHardpoint::setHardpointName(const String& value) {
	hardpointName = value;
}

void ShipCollisionHardpoint::setPosition(const Vector3& value) {
	position = value;
}

void ShipCollisionHardpoint::setSphere(const Sphere& value) {
	sphere = value;
}

void ShipCollisionHardpoint::setBox(const AABB& value) {
	box = value;
}

void ShipCollisionHardpoint::setRotation(Matrix4* value) {
	rotation = value;
}

void ShipCollisionHardpoint::setVolumeType(int value) {
	volumeType = value;
}

void ShipCollisionHardpoint::setRadius(float value) {
	radius = value;
}

void ShipCollisionHardpoint::setSlot(int value) {
	slot = value;
}

void ShipCollisionHardpoint::setTargetable(bool value) {
	targetable = value;
}

const AppearanceTemplate* ShipCollisionHardpoint::getAppearanceTemplate() const {
	return appearance;
}

const String& ShipCollisionHardpoint::getComponentName() const {
	return componentName;
}

const String& ShipCollisionHardpoint::getHardpointName() const {
	return hardpointName;
}

const Vector3& ShipCollisionHardpoint::getPosition() const {
	return position;
}

const Sphere& ShipCollisionHardpoint::getSphere() const {
	return sphere;
}

const AABB& ShipCollisionHardpoint::getBox() const {
	return box;
}

const Matrix4* ShipCollisionHardpoint::getRotation() const {
	return rotation.get();
}

int ShipCollisionHardpoint::getVolumeType() const {
	return volumeType;
}

float ShipCollisionHardpoint::getRadius() const {
	return radius;
}

int ShipCollisionHardpoint::getSlot() const {
	return slot;
}

bool ShipCollisionHardpoint::isTargetable() const {
	return targetable;
}

String ShipCollisionHardpoint::toDebugString() const {
	StringBuffer msg;

	msg << " appearanceName: " << (appearance ? appearance->getFileName() : "") << endl
		<< " componentName:  " << componentName << endl
		<< " hardpointName:  " << hardpointName << endl
		<< " position:       " << position.toString() << endl
		<< " rotation:       " << matrixToDebugString() << endl
		<< " sphere:         " << sphere.getCenter().toString() << ", " << sphere.getRadius() << endl
		<< " box:            " << box.getMinBound()->toString() << ", " << box.getMaxBound()->toString() << endl
		<< " volumeType:     " << volumeType << endl
		<< " slot:           " << Components::shipComponentSlotToString(slot) << endl
		<< " targetable:     " << targetable << endl
		<< "--------------------------------" << endl;

	return msg.toString();
}

String ShipCollisionHardpoint::matrixToDebugString() const {
	const Matrix4& matrix = rotation ? *rotation : Matrix4();
	StringBuffer msg;

	msg << endl
		<< " " << matrix[0][0] << " " << matrix[0][1] << " " << matrix[0][2] << " " << matrix[0][3] << endl
		<< " " << matrix[1][0] << " " << matrix[1][1] << " " << matrix[1][2] << " " << matrix[1][3] << endl
		<< " " << matrix[2][0] << " " << matrix[2][1] << " " << matrix[2][2] << " " << matrix[2][3] << endl
		<< " " << matrix[3][0] << " " << matrix[3][1] << " " << matrix[3][2] << " " << matrix[3][3];

	return msg.toString();
}