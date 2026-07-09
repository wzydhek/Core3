#include "server/zone/objects/ship/ShipObject.h"
#include "server/zone/objects/ship/transform/SpaceTransformType.h"

SpaceTransformType::SpaceTransformType() {
	rotationDamp = Vector3(1.f, 1.f, 1.f);
	rotationRate = Vector3(1.f, 1.f, 0.5f);

	throttleMin = 0.f;
	throttleMax = 1.f;

	transformType = NONE;
}

SpaceTransformType::SpaceTransformType(ShipObject* ship, int type) : Object() {
	initializeType(ship, type);
}

void SpaceTransformType::initializeType(ShipObject* ship, int type) {
	if (ship == nullptr) {
		return;
	}

	setRotationDamp(ship->getBoundingRadius());
	setTransformType(type);
}

void SpaceTransformType::setThrottleRate() {
	switch (transformType) {
		case Type::SLOW: {
			throttleMin = 0.25f;
			throttleMax = 0.5f;
			break;
		}
		case Type::DOCK: {
			throttleMin = 0.f;
			throttleMax = 0.5f;
			break;
		}
		case Type::FAST: {
			throttleMin = 0.5f;
			throttleMax = 1.f;
			break;
		}
		case Type::AUTO:
		case Type::FORM:
		default: {
			throttleMin = 0.f;
			throttleMax = 1.f;
		}
	}
}

void SpaceTransformType::setRotationRate() {
	switch (transformType) {
		case Type::SLOW:
		case Type::DOCK:
		case Type::FORM: {
			rotationRate[Rotation::YAW] = 0.5f;
			rotationRate[Rotation::PITCH] = 0.5f;
			rotationRate[Rotation::ROLL] = 0.5f;
			break;
		}
		case Type::FAST:
		case Type::AUTO:
		default: {
			rotationRate[Rotation::YAW] = 1.f;
			rotationRate[Rotation::PITCH] = 1.f;
			rotationRate[Rotation::ROLL] = 0.5f;
		}
	}

	rotationRate = rotationRate * rotationDamp;
}

void SpaceTransformType::setRotationDamp(float radius) {
	if (radius <= DAMP_RADIUS_MIN) {
		return;
	}

	float rotationMass = Math::clamp(0.f, (float)((radius - DAMP_RADIUS_MIN) / DAMP_RADIUS_MAX), 1.f);

	rotationDamp[Rotation::YAW] = 1.f - (rotationMass * 0.25f);
	rotationDamp[Rotation::PITCH] = 1.f - (rotationMass * 0.5f);
	rotationDamp[Rotation::ROLL] = 1.f - rotationMass;
}

void SpaceTransformType::setTransformType(int type) {
	if (transformType == type) {
		return;
	}

	transformType = type;
	setThrottleRate();
	setRotationRate();
}

const Vector3& SpaceTransformType::getRotationRate() const {
	return rotationRate;
}

float SpaceTransformType::getThrottleMin() const {
	return throttleMin;
}

float SpaceTransformType::getThrottleMid() const {
	return (throttleMax + throttleMin) * 0.5f;
}

float SpaceTransformType::getThrottleMax() const {
	return throttleMax;
}

int SpaceTransformType::getTransformType() const {
	return transformType;
}

String SpaceTransformType::toDebugString(bool includePrivate) const {
	String typeStr = "NONE";

	if (transformType == SLOW) {
		typeStr = "SLOW";
	} else if (transformType == AUTO) {
		typeStr = "AUTO";
	} else if (transformType == FAST) {
		typeStr = "FAST";
	} else if (transformType == DOCK) {
		typeStr = "DOCK";
	} else if (transformType == FORM) {
		typeStr = "FORM";
	}

	StringBuffer msg;
	msg << "SpaceTransformType: " << typeStr << endl << "  throttleMin:      " << throttleMin << endl << "  throttleMax:      " << throttleMax << endl << "  rotationRate:     " << rotationRate.toString() << endl;

	return msg.toString();
}