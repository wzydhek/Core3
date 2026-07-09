#include "PlanetSpawnMap.h"

/**
 * Default constructor.
 */
PlanetSpawnMap::PlanetSpawnMap() {
}

/**
 * Constructor.
 * @param planetName the name of the planet.
 */
PlanetSpawnMap::PlanetSpawnMap(const String& planetName) {
	this->planetName = planetName;
}

/**
 * Finds the city number closest to the supplied position on the planet.
 * @param position the position to search from.
 * @return closest city number or -1 if none is found.
 */
int PlanetSpawnMap::getClosestCityNumber(const Vector3* position) const {
	int city = -1;
	float minSquaredDistance = 100000.0 * 100000.0;
	for (int i = 0; i < citySpawnMaps.size(); i++) {
		float squaredDistance = citySpawnMaps.get(i)->getCityCenter()->distanceTo(*position);
		if (minSquaredDistance >= squaredDistance) {
			minSquaredDistance = squaredDistance;
			city = i;
		}
	}

	return city;
}

/**
 * Loads the object from a LuaObject.
 * @param luaObject object to load from.
 */
void PlanetSpawnMap::readObject(LuaObject* luaObject) {
	planetName = luaObject->getStringField("name");

	// Load npc's.
	LuaObject npcSpawns = luaObject->getObjectField("npcs");

	for (int numberOfSpawns = 1; numberOfSpawns <= npcSpawns.getTableSize(); ++numberOfSpawns) {
		lua_rawgeti(luaObject->getLuaState(), -1, numberOfSpawns);

		LuaObject luaSpawnObj(luaObject->getLuaState());

		Reference<NpcSpawnPoint*> npc = new NpcSpawnPoint();
		npc->readObject(&npcSpawns);

		addToClosestCity(npc, false);

		luaSpawnObj.pop();
	}
	npcSpawns.pop();
}

/**
 * Adds a city on the planet.
 * @param city the city to add.
 */
void PlanetSpawnMap::addCity(Reference<CitySpawnMap*> city) {
	citySpawnMaps.add(city);
}

/**
 * Get the planet name.
 * @return planet name.
 */
const String& PlanetSpawnMap::getPlanetName() const {
	return planetName;
}

/**
 * Finds the city closest to the supplied position on the planet.
 * @param position the position to search from.
 * @return closest city or nullptr if no city is available on the planet.
 */
CitySpawnMap* PlanetSpawnMap::getClosestCity(const Vector3* position) const {
	int cityNumber = getClosestCityNumber(position);

	if (cityNumber >= 0) {
		return citySpawnMaps.get(cityNumber);
	} else {
		return nullptr;
	}
}

const CitySpawnMap* PlanetSpawnMap::getRandomCityNotCloseTo(const Vector3* position) const {
	if (citySpawnMaps.size() == 1) {
		// Only one city, return it.
		return citySpawnMaps.get(0);
	} else if (citySpawnMaps.size() > 1) {
		// Get city number of city closest to the supplied position.
		int closestCityNumber = getClosestCityNumber(position);

		// Generate a random city number.
		int randomCityNumber = System::random(citySpawnMaps.size() - 2);
		if (randomCityNumber >= closestCityNumber) {
			// Add one to the city number to skip the closest city.
			randomCityNumber++;
		}

		return citySpawnMaps.get(randomCityNumber);
	} else {
		// No cities.
		return nullptr;
	}
}

/**
 * Add a NPC to the closest city.
 * @param npc the NPC to add.
 * @param checkDistanceToOtherSpawnPoints if true the distance to all other spawn points in the city
 * is checked and the new spawn point is only added if it is at least a certain distance from all
 * other spawn points.
 * @return the added npc spawn point or the nearest existing spawn point if the supplied spawn point is to close.
 */
NpcSpawnPoint* PlanetSpawnMap::addToClosestCity(NpcSpawnPoint* npc, bool checkDistanceToOtherSpawnPoints) {
	int closestCityNumber = getClosestCityNumber(npc->getPosition());

	if (closestCityNumber >= 0) {
		NpcSpawnPoint* closestNpc = citySpawnMaps.get(closestCityNumber)->getNearestNpcSpawnPoint(npc->getPosition());
		if (!checkDistanceToOtherSpawnPoints || closestNpc == nullptr || (closestNpc->getPosition()->distanceTo(*npc->getPosition()) > 5.0f)) {
			citySpawnMaps.get(closestCityNumber)->addNpc(npc);
			return npc;
		} else {
			return closestNpc;
		}
	}

	return nullptr;
}

/**
 * Remove a spawn point.
 * @param npc the npc spawn point to remove.
 */
void PlanetSpawnMap::remove(NpcSpawnPoint* npc) {
	int closestCityNumber = getClosestCityNumber(npc->getPosition());

	if (closestCityNumber >= 0) {
		citySpawnMaps.get(closestCityNumber)->remove(npc);
	}
}

/**
 * Finds a spawn point on a certain location.
 * @param position the position to search.
 * @return the spawn point on the position or nullptr if none exist.
 */
NpcSpawnPoint* PlanetSpawnMap::findSpawnAt(const Vector3* position) const {
	int closestCityNumber = getClosestCityNumber(position);
	if (closestCityNumber >= 0) {
		return citySpawnMaps.get(closestCityNumber)->findSpawnAt(position);
	}

	return nullptr;
}

/**
 * Load the object from a stream.
 * @param stream the stream to load the object from.
 * @return true if successful.
 */
bool PlanetSpawnMap::parseFromBinaryStream(ObjectInputStream* stream) {
	bool result = planetName.parseFromBinaryStream(stream);
	return result & citySpawnMaps.parseFromBinaryStream(stream);
}

/**
 * Write the object to a stream.
 * @param stream the stream to write the object to.
 * @return true if successful.
 */
bool PlanetSpawnMap::toBinaryStream(ObjectOutputStream* stream) {
	bool result = planetName.toBinaryStream(stream);
	return result & citySpawnMaps.toBinaryStream(stream);
}

/**
 * Saves the spawn points to a file.
 * @param file the file stream to save the spawn points to.
 */
void PlanetSpawnMap::saveSpawnPoints(std::ofstream& file) {
	file << "planet_" << planetName.toCharArray() << " = PlanetSpawnMap:new {" << std::endl;
	file << "\tname = \"" << planetName.toCharArray() << "\"," << std::endl;
	file << "\tnpcs = {" << std::endl;

	int numberOfNpcSpawnPointsInCity = 0;
	bool itemsBefore = false;

	for (int i = 0; i < citySpawnMaps.size(); i++) {
		if (numberOfNpcSpawnPointsInCity > 0) {
			itemsBefore = true;
		}
		numberOfNpcSpawnPointsInCity = citySpawnMaps.get(i)->saveSpawnPoints(file, itemsBefore);
	}

	file << std::endl << "\t}" << std::endl;
	file << "}" << std::endl << std::endl;
	file << "universe:addPlanet(planet_" << planetName.toCharArray() << ");" << std::endl << std::endl;
}