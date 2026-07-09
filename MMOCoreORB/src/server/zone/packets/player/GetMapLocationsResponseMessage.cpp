#include "GetMapLocationsResponseMessage.h"
#include "server/zone/objects/creature/CreatureObject.h"
#include "server/zone/managers/planet/MapLocationEntry.h"

GetMapLocationsResponseMessage::GetMapLocationsResponseMessage(const String& planet, const MapLocationTable* mapLocations, CreatureObject* player) : BaseMessage() {
	insertShort(0x05);
	insertInt(0x9F80464C); // GetMapLocationsResponseMessage

	insertAscii(planet);

	ReadLocker guard(mapLocations);

	insertInt(0);

	int totalEntries = 0;

	try {
		for (int i = 0; i < mapLocations->size(); ++i) {
			const SortedVector<MapLocationEntry>& sortedVector = mapLocations->get(i);

			for (int j = 0; j < sortedVector.size(); ++j) {
				if (sortedVector.elementAt(j).insertToMessage(this, player))
					++totalEntries;
			}
		}

	} catch (Exception& e) {
		System::out << e.getMessage() << endl;
		e.printStackTrace();
	}

	guard.release();

	insertInt(12 + planet.length(), totalEntries);

	insertInt(0); // Blank List
	insertInt(0); // Blank List

	insertInt(0); // Unknown
	insertInt(0); // Unknown
	insertInt(0); // Unknown

	setCompression(true);
}