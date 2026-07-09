#include "PlanetTravelPoint.h"

PlanetTravelPoint::PlanetTravelPoint(const String& zoneName) {
	pointZone = zoneName;
	arrivalVector.set(0.f, 0.f, 0.f);
	interplanetaryTravelAllowed = false;
	incomingTravelAllowed = true;
	shuttleObject = nullptr;
	landingRange = 6.f;
}

PlanetTravelPoint::PlanetTravelPoint(const String& zoneName, const String& cityName, Vector3 arrVector, Vector3 departVector, CreatureObject* shuttle, float range) {
	pointZone = zoneName;
	pointName = cityName;
	arrivalVector = arrVector;
	departureVector = departVector;
	interplanetaryTravelAllowed = false;
	incomingTravelAllowed = true;
	shuttleObject = shuttle;
	landingRange = range;
}

PlanetTravelPoint::PlanetTravelPoint(const PlanetTravelPoint& ptp) : Object() {
	pointZone = ptp.pointZone;
	pointName = ptp.pointName;
	arrivalVector = ptp.arrivalVector;
	departureVector = ptp.departureVector.load();
	interplanetaryTravelAllowed = ptp.interplanetaryTravelAllowed;
	incomingTravelAllowed = ptp.incomingTravelAllowed;
	shuttleObject = ptp.shuttleObject;
	landingRange = ptp.landingRange;
}

PlanetTravelPoint& PlanetTravelPoint::operator=(const PlanetTravelPoint& ptp) {
	if (this == &ptp)
		return *this;

	pointZone = ptp.pointZone;
	pointName = ptp.pointName;
	arrivalVector = ptp.arrivalVector;
	departureVector = ptp.departureVector.load();
	interplanetaryTravelAllowed = ptp.interplanetaryTravelAllowed;
	incomingTravelAllowed = ptp.incomingTravelAllowed;
	shuttleObject = ptp.shuttleObject;
	landingRange = ptp.landingRange;

	return *this;
}

void PlanetTravelPoint::readLuaObject(LuaObject* luaObject) {
	pointName = luaObject->getStringField("name");
	arrivalVector.set(luaObject->getFloatField("x"), luaObject->getFloatField("z"), luaObject->getFloatField("y"));

	departureVector = arrivalVector;

	interplanetaryTravelAllowed = (bool)luaObject->getByteField("interplanetaryTravelAllowed");
	incomingTravelAllowed = (bool)luaObject->getByteField("incomingTravelAllowed");
	landingRange = luaObject->getFloatField("landingRange");
}

// Called by the shuttles and transports to set the shuttle object for the nearest travel point
void PlanetTravelPoint::setShuttle(CreatureObject* shuttle) {
	shuttleObject = shuttle;

	// Departure point is the shuttle's position itself
	departureVector = shuttle->getWorldPosition();
}

void PlanetTravelPoint::setPointName(const String& name) {
	pointName = name;
}

const String& PlanetTravelPoint::getPointZone() const {
	return pointZone;
}

const String& PlanetTravelPoint::getPointName() const {
	return pointName;
}

float PlanetTravelPoint::getArrivalPositionX() const {
	return arrivalVector.getX();
}

float PlanetTravelPoint::getArrivalPositionY() const {
	return arrivalVector.getY();
}

float PlanetTravelPoint::getArrivalPositionZ() const {
	return arrivalVector.getZ();
}

Vector3 PlanetTravelPoint::getArrivalPosition() const {
	return arrivalVector;
}

float PlanetTravelPoint::getDeparturePositionX() const {
	return departureVector.load().getX();
}

float PlanetTravelPoint::getDeparturePositionY() const {
	return departureVector.load().getY();
}

float PlanetTravelPoint::getDeparturePositionZ() const {
	return departureVector.load().getZ();
}

Vector3 PlanetTravelPoint::getDeparturePosition() const {
	return departureVector.load(std::memory_order_relaxed);
}

float PlanetTravelPoint::getLandingRange() const {
	return landingRange;
}

/**
 * Returns true if this point is has the same zone and name that is passed in.
 */
bool PlanetTravelPoint::isPoint(const String& zoneName, const String& name) const {
	return (zoneName == pointZone && name == pointName);
}

/**
 * Returns true if this location allows interplanetary travel
 */
bool PlanetTravelPoint::isInterplanetary() const {
	return interplanetaryTravelAllowed;
}

/**
 * Returns true if this location allows incoming travel
 */
bool PlanetTravelPoint::isIncomingAllowed() const {
	return incomingTravelAllowed;
}

/**
 * Returns true if travel between this point and the passed in point is permitted.
 * @param arrivalPoint The destination point.
 */
bool PlanetTravelPoint::canTravelTo(const PlanetTravelPoint* arrivalPoint) const {
	if (arrivalPoint->getPointZone() == pointZone && arrivalPoint->isIncomingAllowed())
		return true;

	return (interplanetaryTravelAllowed && arrivalPoint->isIncomingAllowed());
}

ManagedReference<CreatureObject*> PlanetTravelPoint::getShuttle() {
	return shuttleObject.get();
}

String PlanetTravelPoint::toString() const {
	StringBuffer buf;

	buf << "[PlanetTravelPoint 0x" + String::hexvalueOf((int64)this) << " Zone = '" << pointZone << "' Name = '" << pointName << "' StarPort = " << interplanetaryTravelAllowed << " Departure: " << departureVector.load().toString() << " Arrival: " << arrivalVector.toString() << " Landing Range: " << landingRange << " shuttle = ";

	buf << "[oid:" << shuttleObject.getSavedObjectID() << "]";

	buf << "]";

	return buf.toString();
}