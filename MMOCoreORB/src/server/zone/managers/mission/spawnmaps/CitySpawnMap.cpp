#include "CitySpawnMap.h"

/**
 * Checks if a spawn point fulfills certain requirements (spawn type, distance and is free to use).
 * @param npc the spawn point to check.
 * @param position the position to check distance from.
 * @param minDistance the minimum distance between the spawn point and the supplied position.
 * @param minDistance the maximum distance between the spawn point and the supplied position.
 * @param spawnType spawn type bitmask that must be fulfilled.
 * @return true if the spawn fulfills spawn type, distance and is free, false otherwise.
 */
bool CitySpawnMap::fulfillsRequirements(NpcSpawnPoint* npc, const Vector3* position, const float minDistance, const float maxDistance, int spawnType) const {
	if (npc != nullptr) {
		if (((npc->getSpawnType() & spawnType) == spawnType)) {
			float squaredDistance = npc->getPosition()->squaredDistanceTo(*position);
			if ((squaredDistance <= maxDistance * maxDistance) && (squaredDistance >= minDistance * minDistance)) {
				// NPC matches requirements.
				return true;
			}
		}
	}

	return false;
}

/**
 * Read the object from a LuaObject.
 * @param luaObject the object to load from.
 */
void CitySpawnMap::readObject(LuaObject* luaObject) {
	cityName = luaObject->getStringAt(2);
	cityCenter.setX(luaObject->getFloatAt(3));
	cityCenter.setY(luaObject->getFloatAt(4));
	radius = luaObject->getFloatAt(5);
}

/**
 * Get the city center coordinates.
 * @return city center position.
 */
const Vector3* CitySpawnMap::getCityCenter() const {
	return &cityCenter;
}

/**
 * Returns a reandom NPC spawn point of the requested spawn type within the minimum and maximum distance
 * from the given position if it exists.
 * @param position The position to measure distance from.
 * @param spawnType the spawn type bit mask needed on the spawn point.
 * @param minDistance minimum distance between the spawn point and the given position.
 * @param maxDistance maximum distance between the spawn point and the given position.
 * @return random spawn point matching the requirements or nullptr if none can be found.
 */
NpcSpawnPoint* CitySpawnMap::getRandomNpcSpawnPoint(const Vector3* position, const int spawnType, const float minDistance, const float maxDistance) const {
	if (npcSpawnMap.size() == 0) {
		return nullptr;
	}

	// Try 100 random npc spawn points, return the first that fulfills the requirements.
	int maximumNumberOfTries = (npcSpawnMap.size() / 4) + 1;
	while (maximumNumberOfTries > 0) {
		int npcNumber = System::random(npcSpawnMap.size() - 1);

		auto npc = npcSpawnMap.get(npcNumber);

		if (fulfillsRequirements(npc, position, minDistance, maxDistance, spawnType)) {
			return npc;
		}

		maximumNumberOfTries--;
	}

	// 100 random npc spawn points failed, do a full iteration and pick the first npc that match.
	for (int i = 0; i < npcSpawnMap.size(); ++i) {
		auto npc = npcSpawnMap.get(i);

		if (fulfillsRequirements(npc, position, minDistance, maxDistance, spawnType)) {
			return npc;
		}
	}

	// No npc matches the requirements.
	return nullptr;
}

/**
 * Add a NPC to the spawn map for the city.
 * @param npc the NPC to add.
 */
void CitySpawnMap::addNpc(NpcSpawnPoint* npc) {
	npcSpawnMap.emplace(npc);
}

/**
 * Remove a spawn point.
 * @param npc the npc spawn point to remove.
 */
void CitySpawnMap::remove(NpcSpawnPoint* npc) {
	npcSpawnMap.removeElement(npc);
}

/**
 * Finds the nearest NPC spawn point.
 * @param position the position to search from.
 * @return the nearest NPC spawn point.
 */
NpcSpawnPoint* CitySpawnMap::getNearestNpcSpawnPoint(const Vector3* position) const {
	float minimumSquaredDistance = 100000.0f * 100000.0f;
	NpcSpawnPoint* nearestNpcSpawnPoint = nullptr;
	// Iterate over all spawn points.
	for (int i = 0; i < npcSpawnMap.size(); i++) {
		// Calculate distance between spawn point and supplied position and store the smallest distance.
		float squaredDistance = npcSpawnMap.get(i)->getPosition()->squaredDistanceTo(*position);
		if (minimumSquaredDistance > squaredDistance) {
			minimumSquaredDistance = squaredDistance;
			nearestNpcSpawnPoint = npcSpawnMap.get(i);
		}
	}

	return nearestNpcSpawnPoint;
}

/**
 * Finds a spawn point on a certain location.
 * @param position the position to search.
 * @return the spawn point on the position or nullptr if none exist.
 */
NpcSpawnPoint* CitySpawnMap::findSpawnAt(const Vector3* position) const {
	for (int i = 0; i < npcSpawnMap.size(); i++) {
		if (npcSpawnMap.get(i)->getPosition()->squaredDistanceTo(*position) < 25.0f) {
			return npcSpawnMap.get(i);
		}
	}

	return nullptr;
}

/**
 * Load the object from a stream.
 * @param stream the stream to load the object from.
 * @return true if successful.
 */
bool CitySpawnMap::parseFromBinaryStream(ObjectInputStream* stream) {
	bool result = cityCenter.parseFromBinaryStream(stream);
	return result & npcSpawnMap.parseFromBinaryStream(stream);
}

/**
 * Write the object to a stream.
 * @param stream the stream to write the object to.
 * @return true if successful.
 */
bool CitySpawnMap::toBinaryStream(ObjectOutputStream* stream) {
	bool result = cityCenter.toBinaryStream(stream);
	return result & npcSpawnMap.toBinaryStream(stream);
}

/**
 * Saves the spawn points to a file.
 * @param file the file stream to save the spawn points to.
 * @param itemsBefore indicates if items has been added before from another city.
 * @return number of npc spawns written.
 */
int CitySpawnMap::saveSpawnPoints(std::ofstream& file, bool itemsBefore) const {
	for (int i = 0; i < npcSpawnMap.size(); i++) {
		if (i > 0 || itemsBefore) {
			file << "," << std::endl;
		}
		npcSpawnMap.get(i)->saveSpawnPoint(file);
	}

	return npcSpawnMap.size();
}