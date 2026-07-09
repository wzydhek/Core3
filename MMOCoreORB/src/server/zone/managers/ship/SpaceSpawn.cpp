#include "SpaceSpawn.h"

SpaceSpawn::SpaceSpawn() : Object() {
	shipSpawnGroupName = "";
	spawnLimit = -1;
	numberToSpawn = 5;
	weighting = 1;
	capitalShipCRC = 0;
}

SpaceSpawn::SpaceSpawn(const SpaceSpawn& spaceSp) : Object() {
	shipSpawnGroupName = spaceSp.shipSpawnGroupName;

	leadShips = spaceSp.leadShips;
	groupShips = spaceSp.groupShips;

	spawnLimit = spaceSp.spawnLimit;
	numberToSpawn = spaceSp.numberToSpawn;
	weighting = spaceSp.weighting;
	capitalShipCRC = spaceSp.capitalShipCRC;
}

SpaceSpawn& SpaceSpawn::operator=(const SpaceSpawn& spaceSp) {
	if (this == &spaceSp) {
		return *this;
	}

	shipSpawnGroupName = spaceSp.shipSpawnGroupName;

	leadShips = spaceSp.leadShips;
	groupShips = spaceSp.groupShips;

	spawnLimit = spaceSp.spawnLimit;
	numberToSpawn = spaceSp.numberToSpawn;
	weighting = spaceSp.weighting;
	capitalShipCRC = spaceSp.capitalShipCRC;

	return *this;
}

void SpaceSpawn::readObject(LuaObject& obj) {
	shipSpawnGroupName = obj.getStringField("shipSpawnGroupName");

	// Logger::console.info(true) << "Reading SpaceSpawn - Group Name: " << shipSpawnGroupName;

	LuaObject leadShipsObj = obj.getObjectField("leadShips");

	if (leadShipsObj.isValidTable()) {
		for (int i = 1; i <= leadShipsObj.getTableSize(); ++i) {
			String leadShip = "object/ship/" + leadShipsObj.getStringAt(i) + ".iff";

			// Logger::console.info(true) << "Adding Lead Ship #" << i << " - " << leadShip;

			leadShips.add(leadShip.hashCode());
		}
	}

	leadShipsObj.pop();

	LuaObject groupShipsObj = obj.getObjectField("groupShips");

	if (groupShipsObj.isValidTable()) {
		for (int i = 1; i <= groupShipsObj.getTableSize(); ++i) {
			String groupShip = "object/ship/" + groupShipsObj.getStringAt(i) + ".iff";

			// Logger::console.info(true) << "Adding Group Ship #" << i << " - " << groupShip;

			groupShips.add(groupShip.hashCode());
		}
	}

	groupShipsObj.pop();

	spawnLimit = obj.getIntField("spawnLimit");
	numberToSpawn = obj.getIntField("numberToSpawn");
	weighting = obj.getIntField("weighting");

	String capitalShip = obj.getStringField("capitalShip");

	if (!capitalShip.isEmpty()) {
		String shipString = "object/ship/" + capitalShip + ".iff";

		// Logger::console.info(true) << "Adding Capital Ship: " << shipString;

		capitalShipCRC = shipString.hashCode();
	}
}

const String& SpaceSpawn::getShipSpawnGroupName() const {
	return shipSpawnGroupName;
}

int SpaceSpawn::getSpawnLimit() const {
	return spawnLimit;
}

int SpaceSpawn::getNumberToSpawn() const {
	return numberToSpawn;
}

int SpaceSpawn::getWeighting() const {
	return weighting;
}

uint32 SpaceSpawn::getRandomLeadShip() {
	if (leadShips.size() < 1) {
		return 0;
	}

	int totalShips = leadShips.size() - 1;

	return (leadShips.get(System::random(totalShips)));
}

uint32 SpaceSpawn::getRandomGroupShip() {
	if (groupShips.size() < 1) {
		return 0;
	}

	int totalShips = groupShips.size() - 1;

	return (groupShips.get(System::random(totalShips)));
}

uint32 SpaceSpawn::getCapitalShipCRC() {
	return capitalShipCRC;
}