#include "ShipProjectileMap.h"

ShipProjectileMapEntry::ShipProjectileMapEntry() : Object() {
}

ShipProjectileMapEntry::~ShipProjectileMapEntry() {
	for (int i = projectileVector.size(); -1 > --i;) {
		remove(i);
	}
}

ShipProjectileMapEntry::ShipProjectileMapEntry(ShipObject* ship) : Object() {
	shipRef = ship;
}

ShipObject* ShipProjectileMapEntry::getShip() {
	return shipRef.get().get();
}

ShipProjectile* ShipProjectileMapEntry::getProjectile(int index) {
	if (projectileVector.size() > index) {
		return projectileVector.get(index);
	}

	return nullptr;
}

void ShipProjectileMapEntry::add(ShipProjectile* projectile) {
	projectileVector.add(projectile);
}

void ShipProjectileMapEntry::remove(int index) {
	if (projectileVector.size() > index) {
		auto entry = projectileVector.get(index);

		if (entry != nullptr) {
			delete entry;
			entry = nullptr;
		}

		projectileVector.remove(index);
	}
}

int ShipProjectileMapEntry::size() const {
	return projectileVector.size();
}

ShipProjectileMap::ShipProjectileMap() {
	projectileMap.setNoDuplicateInsertPlan();
}

ShipObject* ShipProjectileMap::getShip(int mapIndex) {
	ReadLocker lock(&sync);

	if (projectileMap.size() > mapIndex) {
		return projectileMap.elementAt(mapIndex).getValue().getShip();
	}

	return nullptr;
}

ShipProjectileMapEntry* ShipProjectileMap::getEntry(int mapIndex) {
	ReadLocker lock(&sync);

	if (projectileMap.size() > mapIndex) {
		return &projectileMap.elementAt(mapIndex).getValue();
	}

	return nullptr;
}

ShipProjectileMapEntry* ShipProjectileMap::getEntry(ShipObject* ship) {
	ReadLocker lock(&sync);

	uint64 objectID = ship->getObjectID();
	int index = projectileMap.find(objectID);

	if (index != -1) {
		return getEntry(index);
	}

	return nullptr;
}

ShipProjectile* ShipProjectileMap::getProjectile(int mapIndex, int entryIndex) {
	ReadLocker lock(&sync);

	auto entry = getEntry(mapIndex);

	if (entry != nullptr) {
		return entry->getProjectile(entryIndex);
	}

	return nullptr;
}

void ShipProjectileMap::addProjectile(ShipObject* ship, ShipProjectile* projectile) {
	Locker lock(&sync);

	uint64 objectID = ship->getObjectID();
	int index = projectileMap.find(objectID);

	if (index == -1) {
		auto element = VectorMapEntry<uint64, ShipProjectileMapEntry>(objectID, ShipProjectileMapEntry(ship));
		projectileMap.add(std::move(element));
		index = projectileMap.size() - 1;
	}

	auto entry = getEntry(index);

	if (entry != nullptr) {
		entry->add(projectile);
	}
}

void ShipProjectileMap::removeProjectile(int mapIndex, int entryIndex) {
	Locker lock(&sync);

	auto entry = getEntry(mapIndex);

	if (entry != nullptr) {
		entry->remove(entryIndex);
	}
}

void ShipProjectileMap::removeShip(int mapIndex) {
	Locker lock(&sync);

	if (projectileMap.size() > mapIndex) {
		auto entry = getEntry(mapIndex);
		if (entry == nullptr) {
			return;
		}

		for (int i = 0; i < entry->size(); ++i) {
			entry->remove(i);
		}

		projectileMap.remove(mapIndex);
	}
}

int ShipProjectileMap::entrySize(int mapIndex) const {
	ReadLocker lock(&sync);

	if (projectileMap.size() > mapIndex) {
		return projectileMap.elementAt(mapIndex).getValue().size();
	}

	return 0;
}

int ShipProjectileMap::mapSize() const {
	ReadLocker lock(&sync);

	return projectileMap.size();
}