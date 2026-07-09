#include "ShipCountermeasure.h"

ShipCountermeasure::ShipCountermeasure(ShipObject* ship, uint8 weapon, uint8 projectile, uint8 component, Vector3 start, Vector3 end, float projectileSpeed, float projectileRange, float projectileRadius, uint64 miliTime)
	: ShipProjectile(ship, weapon, projectile, component, start, end, projectileSpeed, projectileRange, projectileRadius, miliTime) {
	setLoggingName("ShipCountermeasure");

	effectMax = ship->getComponentMaxDamageMap()->get(ShipObject::WEAPON_COMPONENT_START + weapon);
	effectMin = ship->getComponentMinDamageMap()->get(ShipObject::WEAPON_COMPONENT_START + weapon);

	difficulty = System::random(effectMax - effectMin) + effectMin;
	uniqueID = (System::getMikroTime() << 16) | ship->getUniqueID();

	direction = Vector3(-direction.getX(), -direction.getY(), -direction.getZ());

	deltaMax = countermeasureDuration;
}

bool ShipCountermeasure::isCountermeasure() const {
	return true;
}

// get
int ShipCountermeasure::getEffectMin() const {
	return effectMin;
}

int ShipCountermeasure::getEffectMax() const {
	return effectMax;
}

int ShipCountermeasure::getDifficulty() const {
	return difficulty;
}

// set
void ShipCountermeasure::readCountermeasureData(const ShipCountermeasureData* data) {
	projectileType = data->getCountermeasureType();

	speed = data->getMaxSpeed();
}

void ShipCountermeasure::updatePosition(int deltaTime, int totalTime) {
	float tMinus = totalTime / (float)countermeasureDuration;
	distance = speed * tMinus;
	radius += range * tMinus;

	lastPosition = thisPosition;
	thisPosition = thisPosition + (distance * direction);
}

#ifdef SHIPPROJECTILE_DEBUG
void ShipCountermeasure::debugProjectile(ShipObject* ship, int hitResult) {
	ShipProjectile::debugProjectile(ship, hitResult);

	auto pilot = ship->getPilot();
	if (pilot == nullptr) {
		return;
	}

	StringBuffer msg;

	msg << "Counter: " << endl << " effectMin     " << effectMin << endl << " effectMax     " << effectMax << endl << " duration      " << countermeasureDuration << endl << " difficulty    " << difficulty << endl << "--------------------------------";

	pilot->sendSystemMessage(msg.toString());
}
#endif // SHIPPROJECTILE_DEBUG
