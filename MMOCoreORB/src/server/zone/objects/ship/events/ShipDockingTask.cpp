#include "ShipDockingTask.h"

ShipDockingTask::ShipDockingTask(ShipObject* ship, ShipObject* target) : Task() {
	setLoggingName("ShipDockingTask");

	shipRef = ship;
	targetRef = target;

	timeStart = System::getMiliTime();
	timeTotal = 0;

	rotationTime = 0.f;
	positionTime = 0.f;

	dockingStage = INITIALIZE;
	interlockStatus = false;
}

void ShipDockingTask::run() {
	auto ship = shipRef.get();
	auto target = targetRef.get();

	if (getTimeElapsed() >= DURATION_MAX || !isShipValid(ship) || !isTargetValid(target) || !isDocking(ship) || !isDocking(target)) {
		clearDockingState(ship, target);
		return;
	}

	Locker sLock(ship);
	Locker tLock(target, ship);

	switch (dockingStage) {
		case DockingStage::INITIALIZE: {
			return initializeDocking(ship, target);
		}
		case DockingStage::TRANSFORM: {
			return updateTransform(ship, target);
		}
		case DockingStage::FINALIZE:
		default: {
			return finalizeDocking(ship, target);
		}
	}
}

void ShipDockingTask::initializeDocking(ShipObject* ship, ShipObject* target) {
	sendEffectMessage(ship, "clienteffect/ship_dock_repair_01.cef");

	sendSystemMessage(ship, "@space/cargo:dock_started");
	setDockingTransform(ship, target);

	if (!checkLineOfSight(ship, target)) {
		sendSystemMessage(ship, "@client:autopilot_obstacle");
		sendSystemMessage(ship, "@space/cargo:dock_abort");
		clearDockingState(ship, target);
		return;
	}

	auto shipTransform = ship->getShipTransform();

	if (shipTransform == nullptr) {
		return;
	}

	shipTransform->initializeTransform(ship);
	shipTransform->setNextTransform(dockTransform, SpaceTransformType::DOCK);

	dockingStage = TRANSFORM;
	reschedule(INTERVAL_INITIALIZE);
}

void ShipDockingTask::updateTransform(ShipObject* ship, ShipObject* target) {
	auto transform = ship->getShipTransform();

	if (transform == nullptr) {
		return;
	}

	interlockStatus = transform->getNextDistance() <= 0.f;

	if (dockingStage == TRANSFORM && !interlockStatus) {
		transform->updateTransform(ship);
		return reschedule(INTERVAL_TRANSFORM);
	}

	sendSystemMessage(ship, interlockStatus ? "@space/cargo:dock_achieved" : "@space/cargo:dock_abort");

	dockingStage = FINALIZE;
	reschedule(INTERVAL_FINALIZE);
}

void ShipDockingTask::finalizeDocking(ShipObject* ship, ShipObject* target) {
	sendSystemMessage(ship, "@space/cargo:dock_complete");
	sendEffectMessage(ship, "clienteffect/ship_dock_repair_02.cef");

	clearDockingState(ship, target);
	notifyObservers(ship, target);
}

void ShipDockingTask::notifyObservers(ShipObject* ship, ShipObject* target) {
	Reference<CreatureObject*> pilotRef = ship->getPilot();
	Reference<ShipObject*> targetRef = target;

	Core::getTaskManager()->scheduleTask([pilotRef, targetRef] () {
		if (pilotRef == nullptr || targetRef == nullptr) {
			return;
		}

		Locker lock(pilotRef);
		Locker clocker(targetRef, pilotRef);

		pilotRef->notifyObservers(ObserverEventType::SHIPDOCKED, targetRef, targetRef->getCargoString().hashCode());
	}, "notifyDockedShipLambda", 200);

	sendEffectMessage(ship, "clienteffect/ship_cargo_transfer.cef");
}

void ShipDockingTask::sendSystemMessage(ShipObject* ship, const String& message) {
	ship->sendShipMembersMessage(message);
}

void ShipDockingTask::sendEffectMessage(ShipObject* ship, const String& effect) {
	const auto& position = ship->getPosition();
	ship->broadcastMessage(new PlayClientEffectLoc(effect, "", position.getX(), position.getZ(), position.getY()), true);
}

void ShipDockingTask::clearDockingState(ShipObject* ship, ShipObject* target) const {
	if (ship != nullptr) {
		ship->clearOptionBit(OptionBitmask::DOCKING, true);
	}

	if (target != nullptr) {
		target->clearOptionBit(OptionBitmask::DOCKING, true);
	}
}

void ShipDockingTask::setDockingTransform(ShipObject* ship, ShipObject* target) {
	setAppearanceTransform(ship, target);
	setSpeed(ship);
	setTimeTotal(ship);
}

void ShipDockingTask::setAppearanceTransform(ShipObject* ship, ShipObject* target) {
	auto appearance = target->getAppearanceTemplate();

	if (appearance == nullptr) {
		return;
	}

	auto bounding = ship->getBoundingVolume();

	if (bounding == nullptr) {
		return;
	}

	Vector3 position = Vector3::ZERO;
	Vector3 rotation = Vector3::ZERO;

	Vector3 sLocal = (ship->getPosition() - target->getPosition());
	sLocal = Vector3(sLocal.getX(), sLocal.getZ(), sLocal.getY()) * *target->getRotationMatrix();

	const auto& hardpoints = appearance->getHardpoints();
	float distanceMin = FLT_MAX;

	for (int i = 0; i < hardpoints.size(); ++i) {
		auto key = hardpoints.elementAt(i).getKey();

		if (key.length() != 6 || key.subString(0, key.length()-2) != "dock") {
			continue;
		}

		auto hardpointRotation = hardpoints.elementAt(i).getValue();
		auto hardpointPosition = Vector3(hardpointRotation[3][0], hardpointRotation[3][1]+2.5f, hardpointRotation[3][2]);
		float distanceSqr = hardpointPosition.squaredDistanceTo(sLocal);

		if (distanceMin > distanceSqr) {
			distanceMin = distanceSqr;
			position = hardpointPosition;
			rotation = SpaceMath::matrixToRotation(hardpointRotation);
		}
	}

	Vector3 axisV = getBoundingAxis(ship, target);
	Vector3 axisR = getRotationAxis(axisV);

	if (distanceMin == FLT_MAX) {
		position = getBoundingPosition(target, axisV);
	}

	position = (position + getBoundingPosition(ship, axisV)) * *target->getConjugateMatrix();
	position = Vector3(position.getX(), position.getZ(), position.getY()) + target->getPosition();
	rotation = SpaceMath::getRotationRate(target->getCurrentTransform().getRotation() + rotation + axisR);

	dockTransform.setPosition(position);
	dockTransform.setRotation(rotation);
}

bool ShipDockingTask::checkLineOfSight(ShipObject* ship, ShipObject* target) {
	const auto& sPosition = ship->getPosition();
	const auto& tPosition = dockTransform.getPosition();

	Vector3 velocity = tPosition - sPosition;
	float distance = SpaceMath::qNormalize(velocity);
	float radius = ship->getRadius();

	float intersection =  SpaceMath::getIntersection(target, sPosition, velocity, distance, radius);
	return (distance - intersection) <= radius;
}

Vector3 ShipDockingTask::getBoundingPosition(ShipObject* ship, const Vector3& axis) {
	auto bounding = ship->getBoundingVolume();

	if (bounding == nullptr) {
		return Vector3::ZERO;
	}

	Vector3 position = Vector3::ZERO;

	if (bounding->isBoundingBox()) {
		const auto& box = bounding->getBoundingBox();
		const auto& boundMax = *box.getMaxBound();
		const auto& boundMin = *box.getMinBound();

		Vector3 center = (boundMin + boundMax) * 0.5f;
		float radius = (((boundMax - boundMin) * 0.5f) * axis).length();
		position = center + (axis * radius);
	} else {
		const auto& sphere = bounding->getBoundingSphere();
		const auto& center = sphere.getCenter();

		float radius = sphere.getRadius();
		position = center + (axis * radius);
	}

	return position;
}

Vector3 ShipDockingTask::getBoundingAxis(ShipObject* ship, ShipObject* target) {
	auto bounding = target->getBoundingVolume();

	if (bounding == nullptr) {
		return Vector3::UNIT_Y;
	}

	Vector3 axis = Vector3::UNIT_Y;

	if (bounding->isBoundingBox()) {
		const auto& box = bounding->getBoundingBox();
		const auto& boundMax = *box.getMaxBound();
		const auto& boundMin = *box.getMinBound();

		float minX = (boundMax.getX() - boundMin.getX()) * 0.5f;
		float minY = (boundMax.getY() - boundMin.getY()) * 0.5f;

		if (minX < minY && target->getClientGameObjectType() == SceneObjectType::SHIPTRANSPORT) {
			Vector3 sLocal = ship->getPosition() - target->getPosition();
			sLocal = SpaceMath::getLocalVector(sLocal, *target->getRotationMatrix());

			axis = sLocal.getX() < 0.f ? Vector3(-1,0,0) : Vector3(1,0,0);
		} else {
			axis = fabs(boundMin.getY()) < fabs(boundMax.getY()) ? Vector3(0,-1,0) : Vector3(0,1,0);
		}
	}

	return axis;
}

Vector3 ShipDockingTask::getRotationAxis(const Vector3& boundingAxis) {
	if (boundingAxis == Vector3(1,0,0)) {
		return Vector3(0,0,M_PI_2);
	}

	if (boundingAxis == Vector3(-1,0,0)) {
		return Vector3(0,0,-M_PI_2);
	}

	if (boundingAxis == Vector3(0,-1,0)) {
		return Vector3(0, 0,M_PI);
	}

	return Vector3(0,0,0);
}

uint64 ShipDockingTask::getTimeElapsed() const {
	return System::getMiliTime() - timeStart;
}

void ShipDockingTask::setSpeed(ShipObject* ship) {
	float throttle = 1.f;

	if (rotationTime > 0.f && rotationTime > positionTime) {
		throttle = Math::clamp(0.f, positionTime / rotationTime, 1.f);
	}

	dockTransform.setSpeed(Math::clamp((float)SPEED_MIN, ship->getEngineMaxSpeed() * throttle, (float)SPEED_MAX));
}

void ShipDockingTask::setTimeTotal(ShipObject* ship) {
	const auto& sTransform = ship->getCurrentTransform();
	const auto& sPosition = sTransform.getPosition();
	const auto& sRotation = sTransform.getRotation();
	const auto& dPosition = dockTransform.getPosition();
	const auto& dRotation = dockTransform.getRotation();

	if (sPosition != dPosition) {
		positionTime = sPosition.distanceTo(dPosition) / Math::max(ship->getEngineMaxSpeed() * 0.5f, 1.f);
	}

	if (sRotation != dRotation) {
		float tY = SpaceMath::getRotationRate(dRotation[0], sRotation[0]) / Math::max(ship->getEngineYawRate() * 0.5f, 1.f);
		float tP = SpaceMath::getRotationRate(dRotation[1], sRotation[1]) / Math::max(ship->getEnginePitchRate() * 0.5f, 1.f);
		float tR = SpaceMath::getRotationRate(dRotation[2], sRotation[2]) / Math::max(ship->getEngineRollRate() * 0.5f, 1.f);

		rotationTime = Math::max(tY, Math::max(tP, tR));
	}

	timeTotal = Math::clamp((float)DURATION_MIN, Math::max(positionTime, rotationTime), (float)DURATION_MAX);
}

bool ShipDockingTask::isShipValid(ShipObject* ship) {
	return ship != nullptr && ship->isShipLaunched() && !ship->isHyperspacing() && !ship->isShipDestroyed() && !ship->isShipDisabled();
}

bool ShipDockingTask::isTargetValid(ShipObject* ship) {
	return ship != nullptr && ship->isShipLaunched() && !ship->isHyperspacing() && !ship->isShipDestroyed() && ship->getCurrentSpeed() <= 0.f;
}

bool ShipDockingTask::isDocking(ShipObject* ship) {
	return ship != nullptr && (ship->getOptionsBitmask() & OptionBitmask::DOCKING);
}