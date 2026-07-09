#pragma once

#include "ShipProjectile.h"
#include "server/zone/objects/ship/ShipCountermeasureData.h"
#include "server/zone/packets/jtl/UpdateMissileMessage.h"

class ShipCountermeasure : public ShipProjectile {
public:
	const static unsigned int countermeasureDuration = 1000;

protected:
	int effectMin;
	int effectMax;
	int difficulty;

public:
	ShipCountermeasure(ShipObject* ship, uint8 weapon, uint8 projectile, uint8 component, Vector3 start, Vector3 end, float projectileSpeed, float projectileRange, float projectileRadius, uint64 miliTime);

	bool isCountermeasure() const;

// get
	int getEffectMin() const;

	int getEffectMax() const;

	int getDifficulty() const;

// set
	void readCountermeasureData(const ShipCountermeasureData* data);

	void updatePosition(int deltaTime, int totalTime);

#ifdef SHIPPROJECTILE_DEBUG
	void debugProjectile(ShipObject* ship, int hitResult);
#endif //SHIPPROJECTILE_DEBUG
};
