#pragma once

//#define SHIPPROJECTILE_DEBUG

#include "server/zone/objects/ship/ShipObject.h"
#include "server/zone/objects/ship/ShipProjectileData.h"

#ifdef SHIPPROJECTILE_DEBUG
	#include "server/zone/packets/ui/CreateClientPathMessage.h"
	#include "server/zone/packets/chat/ChatSystemMessage.h"
#endif // SHIPPROJECTILE_DEBUG

class ShipProjectile: public Object, public Logger {
public:
	const static constexpr float positionScale = 7800.f;
	const static constexpr float invPositionScale = 1.f / positionScale;

protected:
	ManagedWeakReference<ShipObject*> shipRef;
	uint32 uniqueID;

	uint8 weaponSlot;
	uint8 projectileType;
	uint8 componentSlot;

	Vector3 thisPosition;
	Vector3 lastPosition;
	Vector3 direction;

	float distance;
	float speed;
	float range;
	float radius;

	uint32 deltaMax;
	uint64 firstUpdate;
	uint64 lastUpdate;

public:
	ShipProjectile();

	ShipProjectile(ShipObject* ship, uint8 weapon, uint8 projectile, uint8 component, Vector3 start, Vector3 end, float projectileSpeed, float projectileRange, float projectileRadius, uint64 miliTime);

	virtual bool isMissile() const;

	virtual bool isCountermeasure() const;

// get
	ManagedWeakReference<ShipObject*> getShip() const;

	uint32 getUniqueID() const;

	uint8 getWeaponSlot() const;

	uint8 getProjectileType() const;

	uint8 getComponentSlot() const;

	const Vector3& getThisPosition() const;

	const Vector3& getLastPosition() const;

	const Vector3& getDirection() const;

	float getDistance() const;

	float getSpeed() const;

	float getRange() const;

	float getRadius() const;

	uint32 getDeltaMax() const;

	uint64 getFirstUpdateTime() const;

	uint64 getLastUpdateTime() const;

// set
	void setLastUpdateTime(const uint64& miliTime);

	void readProjectileData(const ShipProjectileData* data);

	virtual void updatePosition(int deltaTime, int totalTime);

	bool validatePosition() const;

#ifdef SHIPPROJECTILE_DEBUG
	virtual void debugProjectile(ShipObject* ship, int hitResult);

	virtual void debugProjectileMessage(ShipObject* ship, int hitResult);

	virtual void debugProjectilePath(ShipObject* ship);
#endif //SHIPPROJECTILE_DEBUG
};
