#pragma once

#include "ShipProjectile.h"
#include "server/zone/objects/ship/ShipMissileData.h"
#include "server/zone/packets/jtl/UpdateMissileMessage.h"

class ShipMissile : public ShipProjectile {
protected:
	ManagedWeakReference<ShipObject*> targetRef;
	Vector3 hardpointTranslate;

	int timeMin;
	int timeMax;
	int timeToHit;
	int difficulty;

	float clientSpeed;
	float serverSpeed;

public:
	ShipMissile(ShipObject* ship, uint8 weapon, uint8 projectile, uint8 component, Vector3 start, Vector3 end, float projectileSpeed, float projectileRange, float projectileRadius, uint64 miliTime);

	bool isMissile() const;

// get
	ManagedWeakReference<ShipObject*> getTarget() const;

	const Vector3& getHardpointTranslation() const;

	int getTimeMin() const;

	int getTimeMax() const;

	int getTimeToHit() const;

	int getDifficulty() const;

	float getServerSpeed() const;

	float getClientSpeed() const;

// set
	void setTarget(ShipObject* ship);

	void setHardpointTranslation(const Vector3& value);

	void readMissileData(const ShipMissileData* data);

	void calculateTimeToHit();

// update
	void updatePosition(int deltaTime, int totalTime);

	Vector3 getTargetPosition(ShipObject* target, float deltaTime = 0.f) const;

#ifdef SHIPPROJECTILE_DEBUG
	void debugProjectile(ShipObject* ship, int hitResult);

	void debugProjectileMessage(ShipObject* ship, int hitResult);

	void debugProjectilePath(ShipObject* ship);
#endif //SHIPPROJECTILE_DEBUG
};
