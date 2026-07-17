#pragma once

#include "engine/engine.h"
#include "ShipProjectile.h"
#include "server/zone/objects/ship/ShipObject.h"

namespace server {
namespace zone {
namespace managers {
namespace spacecombat {
namespace projectile {

class ShipProjectileMapEntry : public Object {
private:
	ManagedWeakReference<ShipObject*> shipRef;
	Vector<ShipProjectile*> projectileVector;

public:
	ShipProjectileMapEntry();

	~ShipProjectileMapEntry();

	ShipProjectileMapEntry(ShipObject* ship);

	ShipObject* getShip();

	ShipProjectile* getProjectile(int index);

	void add(ShipProjectile* projectile);

	void remove(int index);

	int size() const;
};

class ShipProjectileMap {
private:
	VectorMap<uint64, ShipProjectileMapEntry> projectileMap;
	mutable ReadWriteLock sync;

public:
	ShipProjectileMap();

	ShipObject* getShip(int mapIndex);

	ShipProjectileMapEntry* getEntry(int mapIndex);

	ShipProjectileMapEntry* getEntry(ShipObject* ship);

	ShipProjectile* getProjectile(int mapIndex, int entryIndex);

	void addProjectile(ShipObject* ship, ShipProjectile* projectile);

	void removeProjectile(int mapIndex, int entryIndex);

	void removeShip(int mapIndex);

	int entrySize(int mapIndex) const;

	int mapSize() const;
};

} // namespace projectile
} // namespace spacecombat
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::spacecombat::projectile;
