#include "Transform.h"
#include "server/zone/objects/creature/CreatureObject.h"

#ifdef TRANSFORM_DEBUG
#include "server/zone/packets/ui/CreateClientPathMessage.h"
#include "server/zone/packets/object/ShowFlyText.h"
#endif // TRANSFORM_DEBUG

Transform::Transform() {
	timeStamp = 0u;
	moveCount = 0u;
	parentID = 0ul;

	speed = 0.f;
}

void Transform::parseDataTransform(Message* message) {
	timeStamp = message->parseInt();
	moveCount = message->parseInt();

	parseDirection(message);
	parsePosition(message);

	speed = message->parseFloat();
}

void Transform::parseDataTransformWithParent(Message* message) {
	timeStamp = message->parseInt();
	moveCount = message->parseInt();
	parentID = message->parseLong();

	parseDirection(message);
	parsePosition(message);

	speed = message->parseFloat();
}

void Transform::parseDirection(Message* message) {
	float x = Math::clamp(-1.f, message->parseFloat(), 1.f);
	float y = Math::clamp(-1.f, message->parseFloat(), 1.f);
	float z = Math::clamp(-1.f, message->parseFloat(), 1.f);
	float w = Math::clamp(-1.f, message->parseFloat(), 1.f);

	direction.set(w, x, y, z);
}

void Transform::parsePosition(Message* message) {
	float x = message->parseFloat();
	float z = message->parseFloat();
	float y = message->parseFloat();

	position.set(x, z, y);
}

uint32 Transform::getTimeStamp() const {
	return timeStamp;
}

uint32 Transform::getMoveCount() const {
	return moveCount;
}

uint64 Transform::getParentID() const {
	return parentID;
}

float Transform::getPositionX() const {
	return position.getX();
}

float Transform::getPositionY() const {
	return position.getY();
}

float Transform::getPositionZ() const {
	return position.getZ();
}

float Transform::getSpeed() const {
	return speed;
}

const Vector3& Transform::getPosition() const {
	return position;
}

const Quaternion& Transform::getDirection() const {
	return direction;
}

bool Transform::isPositionValid() const {
#ifdef PLATFORM_WIN
#undef isnan
#undef isinf
#endif // PLATFORM_WIN
	if (std::isnan(position.getX()) || std::isinf(position.getX()) || std::isnan(position.getY()) || std::isinf(position.getY()) || std::isnan(position.getZ()) || std::isinf(position.getZ())) {
		return false;
	}

	if (parentID == 0) {
		if (position.getX() > 8192.f || position.getX() < -8192.f || position.getY() > 8192.f || position.getY() < -8192.f || position.getZ() > 8192.f || position.getZ() < -8192.f) {
			return false;
		}
	} else {
		if (position.getX() > 1024.f || position.getX() < -1024.f || position.getY() > 1024.f || position.getY() < -1024.f || position.getZ() > 1024.f || position.getZ() < -1024.f) {
			return false;
		}
	}

	return true;
}

bool Transform::isPostureValid(int posture) const {
	switch (posture) {
		case 0: // CreaturePosture::UPRIGHT
		case 1: // CreaturePosture::CROUCHED
		case 2: // CreaturePosture::PRONE
		case 3: // CreaturePosture::SNEAKING
		case 8: // CreaturePosture::SITTING
		case 9: // CreaturePosture::SKILLANIMATING
			return true;
		default:
			return false;
	}
}

bool Transform::isInertiaUpdate(const Vector3& creoPosition, const Quaternion* creoDirection, float creoSpeed) const {
	return speed != creoSpeed || isYawUpdate(creoDirection) || getSquaredMoveScale(creoPosition, 1) < 0.975f;
}

bool Transform::isSynchronizeUpdate(const Quaternion* creoDirection, float creoSpeed) const {
	return moveCount >= SYNC_COUNT && speed == 0.f && creoSpeed == 0.f && !isYawUpdate(creoDirection);
}

bool Transform::isYawUpdate(const Quaternion* creoDirection) const {
	float deltaW = creoDirection->getW() - direction.getW();
	float deltaY = creoDirection->getY() - direction.getY();

	return deltaW > 0.001f || deltaW < -0.001f || deltaY > 0.001f || deltaY < -0.001f;
}

float Transform::get2dSquaredDistance(const Vector3& creoPosition) const {
	float deltaX = creoPosition.getX() - position.getX();
	float deltaY = creoPosition.getY() - position.getY();

	return (deltaX * deltaX) + (deltaY * deltaY);
}

float Transform::get3dSquaredDistance(const Vector3& creoPosition) const {
	float deltaX = creoPosition.getX() - position.getX();
	float deltaY = creoPosition.getY() - position.getY();
	float deltaZ = creoPosition.getZ() - position.getZ();

	return (deltaX * deltaX) + (deltaY * deltaY) + (deltaZ * deltaZ);
}

float Transform::getSquaredMoveScale(const Vector3& creoPosition, float interval) const {
	float sqrDistance = get2dSquaredDistance(creoPosition);
	float range = speed * interval * 0.2f;
	float sqrRange = range * range;

	return sqrDistance > sqrRange ? (sqrRange / sqrDistance) : (sqrDistance / sqrRange);
}

float Transform::getMoveScale(const Vector3& creoPosition, float interval) const {
	float distance = sqrt(get2dSquaredDistance(creoPosition));
	float range = speed * interval * 0.2f;

	return distance > range ? (range / distance) : (distance / range);
}

float Transform::getTurnScale(const Quaternion* creoDirection, float radians) const {
	float deltaR = (radians - creoDirection->getRadians()) * M_1_PI;

	return deltaR > 1.f ? (deltaR - 2.f) : deltaR < -1.f ? (deltaR + 2.f) : (deltaR);
}

Vector3 Transform::predictPosition(const Vector3& creoPosition, const Quaternion* creoDirection, int deltaTime) const {
	if (speed < 1.f || deltaTime > MAX_DELTA) {
		return position;
	}

	float interval = (int)(deltaTime * 0.005f);
	float vector = POSITION_MOD;

	vector *= (getMoveScale(creoPosition, interval) * 2.f) - 1.f;

	float deltaX = position.getX() - creoPosition.getX();
	float deltaY = position.getY() - creoPosition.getY();

	if (speed > 2.f && isYawUpdate(creoDirection)) {
		float deltaR = getTurnScale(creoDirection, atan2(deltaX, deltaY)) * M_PI_2;

		vector *= 1.f - (deltaR < 0.f ? (-deltaR) : (deltaR));

		if (deltaR < M_PI_4 && deltaR > -M_PI_4) {
			float cosR = Math::cos(deltaR);
			float sinR = Math::sin(deltaR);

			deltaX = (deltaX * cosR) + (deltaY * sinR);
			deltaY = (-deltaX * sinR) + (deltaY * cosR);
		}
	}

	if (vector <= interval || vector > POSITION_MOD) {
		return position;
	}

	if (interval > 1.f) {
		vector /= interval;
	}

	float x = (deltaX * vector) + creoPosition.getX();
	float y = (deltaY * vector) + creoPosition.getY();

	return Vector3(x, y, position.getZ());
}

bool Transform::isValidParentType(SceneObject* parent) {
	return parent != nullptr && (parent->isCellObject() || (parent->isShipObject() && !parent->isPobShip()) || !parent->isPilotChair() || parent->isOperationsChair() || parent->isShipTurret());
}

#ifdef TRANSFORM_DEBUG
void Transform::sendDebug(CreatureObject* creature, const String& message, const Vector3& newPosition, int deltaTime) const {
	if (message.isEmpty()) {
		return;
	}

	sendFlyText(creature, message, deltaTime);

	if (!message.contains("info") && !message.contains("warning")) {
		sendPathMessage(creature, newPosition);
	}

	if (message.contains("warning") || message.contains("error")) {
		sendSystemMessage(creature, newPosition, message, deltaTime);
	}

	creature->info(true) << message << " -- Delta Time: " << deltaTime << " New Position: " << newPosition.toString();
}

void Transform::sendFlyText(CreatureObject* creature, const String& type, int deltaTime) const {
	if (creature == nullptr)
		return;

	int r = 128;
	int g = 128;
	int b = 128;

	if (type.contains("static")) { // static
		g = b = 0;
	} else if (type.contains("position")) { // position
		r = b = 0;
	} else if (type.contains("prediction")) { // prediction
		r = g = 0;
	} else if (type.contains("synchronize")) { // synchronize
		r = 0;
	} else if (type.contains("error")) { // error
		g = 0;
	} else if (type.contains("warning")) { // warning
		b = 0;
	} else if (type.contains("info")) { // info
		r = g = b = 64;
	}

	auto flyText = new ShowFlyText(creature, type, String::valueOf(deltaTime) + "/ms", r, g, b, 0.5f);
	creature->broadcastMessage(flyText, true);
}

void Transform::sendPathMessage(CreatureObject* creature, const Vector3& newPosition) const {
	if (creature == nullptr)
		return;

	if (parentID != 0.f) {
		return;
	}

	PlayerObject* ghost = creature->getPlayerObject();

	if (ghost == nullptr) {
		return;
	}

	const Vector3& validated = ghost->getLastValidatedPosition()->getPosition();
	const uint64& validParent = ghost->getLastValidatedPosition()->getParent();

	if (validParent != 0) {
		return;
	}

	auto path = new CreateClientPathMessage();

	path->addCoordinate(validated.getX(), validated.getZ(), validated.getY());
	path->addCoordinate(creature->getPositionX(), creature->getPositionZ(), creature->getPositionY());
	path->addCoordinate(position.getX(), position.getZ(), position.getY());
	path->addCoordinate(newPosition.getX(), newPosition.getZ(), newPosition.getY());

	creature->sendMessage(path);
}

void Transform::sendSystemMessage(CreatureObject* creature, const Vector3& newPosition, const String& type, int deltaTime) const {
	PlayerObject* ghost = creature->getPlayerObject();

	if (ghost == nullptr) {
		return;
	}

	const auto lastValidated = ghost->getLastValidatedPosition();

	const Vector3& validated = lastValidated->getPosition();
	const uint64& validParent = lastValidated->getParent();

	StringBuffer msg;

	msg << endl
		<< endl
		<< "--------------------------------"
		<< endl
		// Type
		<< "Error Type - " << type
		<< endl
		// Transform
		<< "Transform: "
		<< " Position: " << newPosition.getX() << ", " << newPosition.getZ() << ", " << newPosition.getY() << " DeltaTime: " << deltaTime
		<< endl
		// Current
		<< "Current: "
		<< " Position: " << creature->getPositionX() << ", " << creature->getPositionZ() << ", " << creature->getPositionY() << " Direction: " << creature->getDirectionW() << ", " << creature->getDirectionX() << ", " << creature->getDirectionY() << ", " << creature->getDirectionZ()
		<< " MoveCount: " << creature->getMovementCounter() << " ParentID: " << creature->getParentID() << " Speed: " << creature->getCurrentSpeed()
		<< endl
		// Parsed
		<< "Parsed: "
		<< " Position: " << position.getX() << ", " << position.getZ() << ", " << position.getY() << " Direction: " << direction.getW() << ", " << direction.getX() << ", " << direction.getY() << ", " << direction.getZ() << " MoveCount: " << moveCount << " ParentID: " << parentID << " Speed: " << speed
		<< endl
		// Validated
		<< "Last Saved Validated: "
		<< " Position: " << validated.getX() << ", " << validated.getZ() << ", " << validated.getY() << " ParentID: " << validParent << " Zone: " << ghost->getSavedTerrainName() << endl
		<< "--------------------------------" << endl
		<< endl
		<< endl;

	creature->info(true) << msg.toString();
	creature->sendSystemMessage(msg.toString());
}
#endif // TRANSFORM_DEBUG