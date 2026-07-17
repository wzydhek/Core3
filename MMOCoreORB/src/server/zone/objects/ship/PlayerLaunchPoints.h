#pragma once

#include "system/lang/Object.h"
#include "engine/util/u3d/Vector3.h"
#include "system/util/VectorMap.h"

namespace server {
namespace zone {
namespace objects {
namespace ship {

class PlayerLaunchPoints : public Object {
protected:
	VectorMap<String, Vector<Vector3>> spawnLocations;

public:
	PlayerLaunchPoints();

	PlayerLaunchPoints(const PlayerLaunchPoints& points);

	PlayerLaunchPoints& operator=(const PlayerLaunchPoints& points);

	void addLaunchPoint(String cellName, Vector3 location);

	int getTotalLaunchCells();

	const String getRandomCell();

	const Vector<Vector3>& getSpawnLocations(String cellName);

	bool toBinaryStream(ObjectOutputStream* stream);

	bool parseFromBinaryStream(ObjectInputStream* stream);
};

} // namespace ship
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::ship;
