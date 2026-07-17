//
// Created by g on 12/20/17.
//

#pragma once

#include "server/zone/objects/creature/CreatureObject.h"
#include "server/zone/objects/ship/ShipObject.h"
#include "server/zone/ZoneClientSession.h"


//#define DEBUG_HYPERSPACE

namespace server {
namespace zone {
namespace objects {
namespace ship {
namespace events {

class HyperspaceToLocationTask : public Task {
	WeakReference<CreatureObject*> play;
	WeakReference<ShipObject*> ship;
	String zoneName;
	Vector3 location;
	int iteration;

public:
	HyperspaceToLocationTask(CreatureObject* pl, ShipObject* ship, const String& zoneName, const Vector3& location);

	void run();

#ifdef DEBUG_HYPERSPACE
	void startPacketLoggingForShip(ShipObject* shipObject);

	void stopPacketLoggingForShip(ShipObject* shipObject);
#endif // DEBUG_HYPERSPACE
};

} // namespace events
} // namespace ship
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::ship::events;
