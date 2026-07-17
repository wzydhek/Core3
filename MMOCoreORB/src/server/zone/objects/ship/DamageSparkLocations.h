#pragma once

#include "system/lang/Object.h"
#include "engine/util/u3d/Vector3.h"
#include "system/util/VectorMap.h"

namespace server {
namespace zone {
namespace objects {
namespace ship {

class DamageSparkLocations : public Object {
protected:
	VectorMap<String, Vector<Vector3>> sparkLocations;

public:
	DamageSparkLocations() {
	}

	DamageSparkLocations(const DamageSparkLocations& locations) : Object() {
		sparkLocations = locations.sparkLocations;
	}

	DamageSparkLocations& operator=(const DamageSparkLocations& locations) {
		if (this == &locations)
			return *this;

		sparkLocations = locations.sparkLocations;

		return *this;
	}

	void addSparkLocation(String cellName, Vector3 location) {
		Vector<Vector3> cellLocs = sparkLocations.get(cellName);
		cellLocs.add(location);

		sparkLocations.put(cellName, cellLocs);
	}

	inline int getTotalSparkCells() {
		return sparkLocations.size();
	}

	const inline String getRandomCell() {
		int totalCells = getTotalSparkCells();
		int random = System::random(totalCells - 1);
		String cellName = sparkLocations.elementAt(random).getKey();

		return cellName;
	}

	const inline Vector<Vector3>& getSparkLocations(String cellName) {
		return sparkLocations.get(cellName);
	}

	bool toBinaryStream(ObjectOutputStream* stream) {
		sparkLocations.toBinaryStream(stream);

		return true;
	}

	bool parseFromBinaryStream(ObjectInputStream* stream) {
		sparkLocations.parseFromBinaryStream(stream);

		return true;
	}
};

} // namespace ship
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::ship;
