/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "CitySpawnMap.h"

namespace server {
namespace zone {
namespace managers {
namespace mission {
namespace spawnmaps {

/**
 * Container for all cities on a planet and their mission NPC spawn points.
 */
class PlanetSpawnMap : public Object, Logger {
protected:
	/**
	 * Vector of cities.
	 */
	Vector<Reference<CitySpawnMap*> > citySpawnMaps;

	/**
	 * Name of the planet.
	 */
	String planetName;

	/**
	 * Finds the city number closest to the supplied position on the planet.
	 * @param position the position to search from.
	 * @return closest city number or -1 if none is found.
	 */
	int getClosestCityNumber(const Vector3* position) const;

public:
	/**
	 * Default constructor.
	 */
	PlanetSpawnMap();

	/**
	 * Constructor.
	 * @param planetName the name of the planet.
	 */
	PlanetSpawnMap(const String& planetName);

	/**
	 * Loads the object from a LuaObject.
	 * @param luaObject object to load from.
	 */
	void readObject(LuaObject* luaObject);

	/**
	 * Adds a city on the planet.
	 * @param city the city to add.
	 */
	void addCity(Reference<CitySpawnMap*> city);

	/**
	 * Get the planet name.
	 * @return planet name.
	 */
	const String& getPlanetName() const;

	/**
	 * Finds the city closest to the supplied position on the planet.
	 * @param position the position to search from.
	 * @return closest city or nullptr if no city is available on the planet.
	 */
	CitySpawnMap* getClosestCity(const Vector3* position) const;

	const CitySpawnMap* getRandomCityNotCloseTo(const Vector3* position) const;

	/**
	 * Add a NPC to the closest city.
	 * @param npc the NPC to add.
	 * @param checkDistanceToOtherSpawnPoints if true the distance to all other spawn points in the city
	 * is checked and the new spawn point is only added if it is at least a certain distance from all
	 * other spawn points.
	 * @return the added npc spawn point or the nearest existing spawn point if the supplied spawn point is to close.
	 */
	NpcSpawnPoint* addToClosestCity(NpcSpawnPoint* npc, bool checkDistanceToOtherSpawnPoints);

	/**
	 * Remove a spawn point.
	 * @param npc the npc spawn point to remove.
	 */
	void remove(NpcSpawnPoint* npc);

	/**
	 * Finds a spawn point on a certain location.
	 * @param position the position to search.
	 * @return the spawn point on the position or nullptr if none exist.
	 */
	NpcSpawnPoint* findSpawnAt(const Vector3* position) const;

	/**
	 * Load the object from a stream.
	 * @param stream the stream to load the object from.
	 * @return true if successful.
	 */
	bool parseFromBinaryStream(ObjectInputStream* stream);

	/**
	 * Write the object to a stream.
	 * @param stream the stream to write the object to.
	 * @return true if successful.
	 */
	bool toBinaryStream(ObjectOutputStream* stream);

	/**
	 * Saves the spawn points to a file.
	 * @param file the file stream to save the spawn points to.
	 */
	void saveSpawnPoints(std::ofstream& file);
};

} // namespace spawnmaps
} // namespace mission
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::mission::spawnmaps;
