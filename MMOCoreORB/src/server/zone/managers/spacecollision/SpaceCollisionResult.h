#pragma once

//#define SPACECOLLISION_DEBUG

#include "server/zone/objects/ship/ShipObject.h"
#include "server/zone/managers/ship/ShipManager.h"
#include "server/zone/managers/spacecombat/projectile/ShipProjectile.h"

#ifdef SPACECOLLISION_DEBUG
	#include "server/zone/packets/ui/CreateClientPathMessage.h"
#endif // SPACECOLLISION_DEBUG

class SpaceCollisionEntry {
protected:
	ManagedWeakReference<SceneObject*> object;
	Vector3 position;
	Vector3 direction;

	float distance;
	int slot;

public:
	SpaceCollisionEntry();

	SpaceCollisionEntry(SceneObject* target, const ShipProjectile* projectile, const Vector3& localDirection, float intersection, int componentSlot = -1);

	ManagedWeakReference<SceneObject*> getObject() const;

	const Vector3& getPosition() const;

	const Vector3& getDirection() const;

	float getDistance() const;

	bool isHitFront() const;

	int getSlot() const;
};

class SpaceCollisionResult {
protected:
	VectorMap<float, SpaceCollisionEntry> collisionMap;

public:
	SpaceCollisionResult();

	void setCollision(SceneObject* target, const ShipProjectile* projectile, const Vector3& localDirection, float intersection, int componentSlot = Components::CHASSIS);

	ManagedWeakReference<SceneObject*> getObject(int index = 0) const;

	const Vector3& getPosition(int index = 0) const;

	const Vector3& getDirection(int index = 0) const;

	float getDistance(int index = 0) const;

	bool isHitFront(int index = 0) const;

	int getSlot(int index = 0) const;

	int size() const;

#ifdef SPACECOLLISION_DEBUG
	void debugCollision(ShipObject* ship, const ShipProjectile* projectile);

	String debugCollisionHardpoints(ShipObject* targetShip, const Vector3& targetPosition, const Matrix4& targetRotation, const ShipCollisionData* targetData, CreateClientPathMessage* path);
#endif // SPACECOLLISION_DEBUG
};
