/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "PlanetSpawnMap.h"

namespace server {
namespace zone {
namespace managers {
namespace mission {
namespace spawnmaps {

/**
 * Container for all planets in the universe and their spawn points.
 */
class UniverseSpawnMap : public Object, Logger {
protected:
	/**
	 * Map for all planets and their spawn points.
	 */
	VectorMap<uint32, Reference<PlanetSpawnMap* > > planetSpawnMaps;

public:
	/**
	 * Remove all stored spawn maps.
	 */
	void clear();

	/**
	 * Read the object from a LuaObject.
	 * @param luaObject the object to load from.
	 */
	void readObject(LuaObject* luaObject);

	/**
	 * Add cities from lua object.
	 * @param cities the cities to add.
	 */
	void addCities(LuaObject* cities);

	/**
	 * Return a requested planet.
	 * @param planetName the name of the planet.
	 * @return the requested planet.
	 */
	PlanetSpawnMap* getPlanet(const uint32 planetCRC);

	const PlanetSpawnMap* getPlanet(const uint32 planetCRC) const;

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
