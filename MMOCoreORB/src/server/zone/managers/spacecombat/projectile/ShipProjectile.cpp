#include "ShipProjectile.h"

ShipProjectile::ShipProjectile() {
	setLoggingName("ShipProjectile");

	uniqueID = 0;

	weaponSlot = 0;
	projectileType = 0;
	componentSlot = 0;

	distance = 0.f;
	speed = 0.f;
	range = 0.f;
	radius = 0.f;

	deltaMax = 0;

	firstUpdate = 0;
	lastUpdate = 0;
}

ShipProjectile::ShipProjectile(ShipObject* ship, uint8 weapon, uint8 projectile, uint8 component, Vector3 start, Vector3 end, float projectileSpeed, float projectileRange, float projectileRadius, uint64 miliTime) {
	setLoggingName("ShipProjectile");

	this->shipRef = ship;

	uniqueID = 0;

	weaponSlot = weapon;
	projectileType = projectile;
	componentSlot = component;

	thisPosition = start;
	lastPosition = start;
	direction = end * invPositionScale;

	distance = 0.f;
	speed = projectileSpeed;
	range = projectileRange;
	radius = projectileRadius;

	deltaMax = (projectileRange / projectileSpeed) * 1000.f;
	firstUpdate = miliTime - 200; // SpaceCombatManager::CheckProjectilesTask::INTERVAL;
	lastUpdate = firstUpdate;
}

bool ShipProjectile::isMissile() const {
	return false;
}

bool ShipProjectile::isCountermeasure() const {
	return false;
}

// get
ManagedWeakReference<ShipObject*> ShipProjectile::getShip() const {
	return shipRef;
}

uint32 ShipProjectile::getUniqueID() const {
	return uniqueID;
}

uint8 ShipProjectile::getWeaponSlot() const {
	return weaponSlot;
}

uint8 ShipProjectile::getProjectileType() const {
	return projectileType;
}

uint8 ShipProjectile::getComponentSlot() const {
	return componentSlot;
}

const Vector3& ShipProjectile::getThisPosition() const {
	return thisPosition;
}

const Vector3& ShipProjectile::getLastPosition() const {
	return lastPosition;
}

const Vector3& ShipProjectile::getDirection() const {
	return direction;
}

float ShipProjectile::getDistance() const {
	return distance;
}

float ShipProjectile::getSpeed() const {
	return speed;
}

float ShipProjectile::getRange() const {
	return range;
}

float ShipProjectile::getRadius() const {
	return radius;
}

uint32 ShipProjectile::getDeltaMax() const {
	return deltaMax;
}

uint64 ShipProjectile::getFirstUpdateTime() const {
	return firstUpdate;
}

uint64 ShipProjectile::getLastUpdateTime() const {
	return lastUpdate;
}

// set
void ShipProjectile::setLastUpdateTime(const uint64& miliTime) {
	lastUpdate = miliTime;
}

void ShipProjectile::readProjectileData(const ShipProjectileData* data) {
	projectileType = data->getIndex();

	speed = data->getSpeed();
	range = data->getRange();

	deltaMax = (range / speed) * 1000.f;
}

void ShipProjectile::updatePosition(int deltaTime, int totalTime) {
	distance = deltaTime * speed * 0.001f;

	lastPosition = thisPosition;
	thisPosition = thisPosition + (distance * direction);
}

bool ShipProjectile::validatePosition() const {
	if (thisPosition.getX() > 7999.f || thisPosition.getX() < -7999.f || thisPosition.getY() > 7999.f || thisPosition.getY() < -7999.f || thisPosition.getZ() > 7999.f || thisPosition.getZ() < -7999.f) {
		return false;
	}

	return distance > 0.f;
}

#ifdef SHIPPROJECTILE_DEBUG
virtual void ShipProjectile::debugProjectile(ShipObject* ship, int hitResult) {
	debugProjectileMessage(ship, hitResult);
	debugProjectilePath(ship);
}

virtual void ShipProjectile::debugProjectileMessage(ShipObject* ship, int hitResult) {
	StringBuffer msg;

	msg << "Projectile:     "
		<< (hitResult == 1	 ? "HIT"
			: hitResult == 0 ? "MISS"
							 : "EXPIRE")
		<< endl
		<< " weaponSlot     " << weaponSlot << endl
		<< " projectileType " << projectileType << endl
		<< " componentSlot  " << componentSlot << endl
		<< " thisPosition   " << thisPosition.toString() << endl
		<< " lastPosition   " << lastPosition.toString() << endl
		<< " direction      " << direction.toString() << endl
		<< " distance       " << distance << endl
		<< " speed          " << speed << endl
		<< " range          " << range << endl
		<< " radius         " << radius << endl
		<< " deltaMax       " << deltaMax << endl
		<< " totalTime      " << (System::getMiliTime() - firstUpdate) << endl
		<< " deltaTime      " << (System::getMiliTime() - lastUpdate) << endl
		<< "--------------------------------";

	auto smsg = new ChatSystemMessage(msg.toString());
	ship->broadcastMessage(smsg, true);
}

virtual void ShipProjectile::debugProjectilePath(ShipObject* ship) {
	auto path = new CreateClientPathMessage();

	path->addCoordinate(lastPosition);
	path->drawBoundingSphere(thisPosition, Matrix4(), Sphere(Vector3::ZERO, radius));
	path->addCoordinate(thisPosition);

	ship->broadcastMessage(path, true);
}
#endif // SHIPPROJECTILE_DEBUG
