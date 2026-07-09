/*
 * SpaceSpawn.h
 *
 *  Created on: 2024-09-15
 *  Author: Hakry
 */

#pragma once

#include "engine/engine.h"

namespace server {
namespace zone {
namespace managers {
namespace ship {

class SpaceSpawn : public Object {
	protected:
		String shipSpawnGroupName;

		Vector<uint32> leadShips;
		Vector<uint32> groupShips;

		int spawnLimit;
		int numberToSpawn;
		int weighting;
		uint32 capitalShipCRC;

	public:
		SpaceSpawn();

		SpaceSpawn(const SpaceSpawn& spaceSp);

		SpaceSpawn& operator=(const SpaceSpawn& spaceSp);

		void readObject(LuaObject& obj);

		const String& getShipSpawnGroupName() const;

		int getSpawnLimit() const;

		int getNumberToSpawn() const;

		int getWeighting() const;

		uint32 getRandomLeadShip();

		uint32 getRandomGroupShip();

		uint32 getCapitalShipCRC();
};

} // ship
} // managers
} // zone
} // server

using namespace server::zone::managers::ship;
