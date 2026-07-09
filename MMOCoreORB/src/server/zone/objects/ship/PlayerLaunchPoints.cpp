#include "PlayerLaunchPoints.h"

PlayerLaunchPoints::PlayerLaunchPoints() {
}

PlayerLaunchPoints::PlayerLaunchPoints(const PlayerLaunchPoints& points) : Object() {
	spawnLocations = points.spawnLocations;
}

PlayerLaunchPoints& PlayerLaunchPoints::operator=(const PlayerLaunchPoints& points) {
	if (this == &points)
		return *this;

	spawnLocations = points.spawnLocations;

	return *this;
}

void PlayerLaunchPoints::addLaunchPoint(String cellName, Vector3 location) {
	Vector<Vector3> cellLocs = spawnLocations.get(cellName);

	cellLocs.add(location);
	spawnLocations.put(cellName, cellLocs);
}

int PlayerLaunchPoints::getTotalLaunchCells() {
	return spawnLocations.size();
}

const String PlayerLaunchPoints::getRandomCell() {
	int totalCells = getTotalLaunchCells();

	if (totalCells <= 0) {
		return "";
	} else if (totalCells == 1) {
		return spawnLocations.elementAt(0).getKey();
	}

	int random = System::random((totalCells - 1));
	String cellName = spawnLocations.elementAt(random).getKey();

	return cellName;
}

const Vector<Vector3>& PlayerLaunchPoints::getSpawnLocations(String cellName) {
	return spawnLocations.get(cellName);
}

bool PlayerLaunchPoints::toBinaryStream(ObjectOutputStream* stream) {
	spawnLocations.toBinaryStream(stream);

	return true;
}

bool PlayerLaunchPoints::parseFromBinaryStream(ObjectInputStream* stream) {
	spawnLocations.parseFromBinaryStream(stream);

	return true;
}