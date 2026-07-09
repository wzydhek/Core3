#include "SpacePatrolPoint.h"

SpacePatrolPoint::SpacePatrolPoint() {
	reached = true;
	evadePoint = false;

	addSerializableVariables();
}

SpacePatrolPoint::SpacePatrolPoint(const Vector3& pos) : position(pos, nullptr) {
	reached = false;
	evadePoint = false;

	addSerializableVariables();
}

SpacePatrolPoint::SpacePatrolPoint(const SpacePatrolPoint& point) : Object(), Serializable() {
	position = point.position;
	direction = point.direction;
	reached = point.reached;
	evadePoint = point.evadePoint;

	addSerializableVariables();
}

#ifdef CXX11_COMPILER
SpacePatrolPoint::SpacePatrolPoint(SpacePatrolPoint&& point) : Object(), Serializable(), position(std::move(point.position)), reached(point.reached), evadePoint(point.evadePoint), estimatedTimeOfArrival(point.estimatedTimeOfArrival) {
	addSerializableVariables();
}
#endif

SpacePatrolPoint& SpacePatrolPoint::operator=(const SpacePatrolPoint& p) {
	if (this == &p)
		return *this;

	position = p.position;
	reached = p.reached;
	evadePoint = p.evadePoint;
	direction = p.direction;
	estimatedTimeOfArrival = p.estimatedTimeOfArrival;

	return *this;
}

#ifdef CXX11_COMPILER
SpacePatrolPoint& SpacePatrolPoint::operator=(SpacePatrolPoint&& p) {
	if (this == &p)
		return *this;

	position = std::move(p.position);
	reached = p.reached;
	evadePoint = p.evadePoint;
	direction = p.direction;
	estimatedTimeOfArrival = p.estimatedTimeOfArrival;

	return *this;
}
#endif

bool SpacePatrolPoint::operator!=(const Vector3& location) const {
	return position.getX() != location.getX() || position.getZ() != location.getZ() || position.getY() != location.getY();
}

void SpacePatrolPoint::addSerializableVariables() {
	addSerializableVariable("position", &position);
	addSerializableVariable("reached", &reached);
	addSerializableVariable("evadePoint", &evadePoint);
	addSerializableVariable("direction", &direction);
	addSerializableVariable("estimatedTimeOfArrival", &estimatedTimeOfArrival);
}

void to_json(nlohmann::json& j, const SpacePatrolPoint& p) {
	j["position"] = p.position;
	j["reached"] = p.reached;
	j["evadePoint"] = p.evadePoint;
	j["direction"] = p.direction;
	j["estimatedTimeOfArrival"] = p.estimatedTimeOfArrival;
}

Vector3 SpacePatrolPoint::getWorldPosition() {
	return position.getWorldPosition();
}

bool SpacePatrolPoint::isInRange(SceneObject* obj, float range) {
	Vector3 thisWorldPos = getWorldPosition();
	Vector3 objWorldPos = obj->getWorldPosition();

	return thisWorldPos.squaredDistanceTo(objWorldPos) <= (range * range);
}

bool SpacePatrolPoint::isInRange(SpacePatrolPoint* obj, float range) {
	Vector3 thisWorldPos = getWorldPosition();
	Vector3 objWorldPos = obj->getWorldPosition();

	return thisWorldPos.squaredDistanceTo(objWorldPos) <= (range * range);
}

const WorldCoordinates& SpacePatrolPoint::getCoordinates() const {
	return position;
}

// getters
float SpacePatrolPoint::getPositionX() const {
	return position.getX();
}

float SpacePatrolPoint::getPositionY() const {
	return position.getY();
}

float SpacePatrolPoint::getPositionZ() const {
	return position.getZ();
}

Quaternion SpacePatrolPoint::getDirection() const {
	return direction;
}

Time* SpacePatrolPoint::getEstimatedTimeOfArrival() {
	return &estimatedTimeOfArrival;
}

bool SpacePatrolPoint::isReached() const {
	return reached;
}

bool SpacePatrolPoint::isEvadePoint() const {
	return evadePoint;
}

bool SpacePatrolPoint::isPastTimeOfArrival() {
	return estimatedTimeOfArrival.isPast() || estimatedTimeOfArrival.isPresent();
}

// setters
void SpacePatrolPoint::setPosition(float x, float z, float y) {
	position.setCoordinates(Vector3(x, y, z));
}

void SpacePatrolPoint::setPositionX(float x) {
	position.setX(x);
}

void SpacePatrolPoint::setPositionZ(float z) {
	position.setZ(z);
}

void SpacePatrolPoint::setPositionY(float y) {
	position.setY(y);
}

void SpacePatrolPoint::setCell(CellObject* cell) {
	position.setCell(cell);
}

void SpacePatrolPoint::setDirection(float fw, float fx, float fy, float fz) {
	direction.set(fw, fx, fy, fz);
}

void SpacePatrolPoint::setReached(bool value) {
	reached = value;
}

void SpacePatrolPoint::setEvadePoint(bool value) {
	evadePoint = value;
}

void SpacePatrolPoint::addEstimatedTimeOfArrival(uint32 mili) {
	estimatedTimeOfArrival.updateToCurrentTime();
	estimatedTimeOfArrival.addMiliTime(mili);
}

/**
 * Returns the string representation of the vector in (x, y, z) format plus the cellID.
 */
String SpacePatrolPoint::toString() const {
	StringBuffer msg;
	msg << position.toString() << " isReached: " << (reached ? "true" : "false") << " isEvadePoint: " << (evadePoint ? "true" : "false");
	return msg.toString();
}