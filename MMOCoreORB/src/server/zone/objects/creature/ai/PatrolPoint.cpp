#include "PatrolPoint.h"

PatrolPoint::PatrolPoint() {
	reached = true;

	addSerializableVariables();
}

PatrolPoint::PatrolPoint(const Vector3& pos, CellObject* cell) : position(pos, cell) {
	reached = false;

	addSerializableVariables();
}

PatrolPoint::PatrolPoint(float posX, float posZ, float posY, CellObject* cell) : position(Vector3(posX, posY, posZ), cell) {
	reached = false;

	addSerializableVariables();
}

PatrolPoint::PatrolPoint(const PatrolPoint& point) : Object(), Serializable() {
	position = point.position;

	reached = point.reached;

	addSerializableVariables();
}

#ifdef CXX11_COMPILER
PatrolPoint::PatrolPoint(PatrolPoint&& point) : Object(), Serializable(), position(std::move(point.position)), reached(point.reached), estimatedTimeOfArrival(point.estimatedTimeOfArrival) {
	addSerializableVariables();
}
#endif

PatrolPoint& PatrolPoint::operator=(const PatrolPoint& p) {
	if (this == &p)
		return *this;

	position = p.position;

	reached = p.reached;

	direction = p.direction;

	estimatedTimeOfArrival = p.estimatedTimeOfArrival;

	return *this;
}

#ifdef CXX11_COMPILER
PatrolPoint& PatrolPoint::operator=(PatrolPoint&& p) {
	if (this == &p)
		return *this;

	position = std::move(p.position);

	reached = p.reached;

	direction = p.direction;

	estimatedTimeOfArrival = p.estimatedTimeOfArrival;

	return *this;
}
#endif

void PatrolPoint::addSerializableVariables() {
	addSerializableVariable("position", &position);
	addSerializableVariable("reached", &reached);
	addSerializableVariable("direction", &direction);
	addSerializableVariable("estimatedTimeOfArrival", &estimatedTimeOfArrival);
}

Vector3 PatrolPoint::getWorldPosition() {
	return position.getWorldPosition();
}

bool PatrolPoint::isInRange(SceneObject* obj, float range) {
	Vector3 thisWorldPos = getWorldPosition();
	Vector3 objWorldPos = obj->getWorldPosition();

	return thisWorldPos.squaredDistanceTo(objWorldPos) < (range * range);
}

bool PatrolPoint::isInRange(PatrolPoint* obj, float range) {
	Vector3 thisWorldPos = getWorldPosition();
	Vector3 objWorldPos = obj->getWorldPosition();

	return thisWorldPos.squaredDistanceTo(objWorldPos) <= (range * range);
}

const WorldCoordinates& PatrolPoint::getCoordinates() const {
	return position;
}

// getters
float PatrolPoint::getPositionX() const {
	return position.getX();
}

float PatrolPoint::getPositionY() const {
	return position.getY();
}

float PatrolPoint::getPositionZ() const {
	return position.getZ();
}

CellObject* PatrolPoint::getCell() const {
	return position.getCell();
}

float PatrolPoint::getDirection() const {
	return direction;
}

Time* PatrolPoint::getEstimatedTimeOfArrival() {
	return &estimatedTimeOfArrival;
}

bool PatrolPoint::isReached() const {
	return reached;
}

bool PatrolPoint::isPastTimeOfArrival() {
	return estimatedTimeOfArrival.isPast() || estimatedTimeOfArrival.isPresent();
}

// setters
void PatrolPoint::setPosition(float x, float z, float y) {
	position.setCoordinates(Vector3(x, y, z));
}

void PatrolPoint::setPositionX(float x) {
	position.setX(x);
}

void PatrolPoint::setPositionZ(float z) {
	position.setZ(z);
}

void PatrolPoint::setPositionY(float y) {
	position.setY(y);
}

void PatrolPoint::setCell(CellObject* cell) {
	position.setCell(cell);
}

void PatrolPoint::setDirection(float dir) {
	direction = dir;
}

void PatrolPoint::setReached(bool value) {
	reached = value;
}

void PatrolPoint::addEstimatedTimeOfArrival(uint32 mili) {
	estimatedTimeOfArrival.updateToCurrentTime();
	estimatedTimeOfArrival.addMiliTime(mili);
}

/**
 * Returns the string representation of the vector in (x, y, z) format plus the cellID.
 */
String PatrolPoint::toString() const {
	return position.toString();
}

void server::zone::objects::creature::ai::to_json(nlohmann::json& j, const PatrolPoint& p) {
	j["position"] = p.position;
	j["reached"] = p.reached;
	j["direction"] = p.direction;
	j["estimatedTimeOfArrival"] = p.estimatedTimeOfArrival;
}
