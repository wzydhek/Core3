/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

/*
 * Updated on: Thu Oct 13 08:16:00 PDT 2011 by lordkator - Fixes to make travel debugging easier and fixed dialog timing
 */

#pragma once

#include "QueueCommand.h"
#include "server/zone/objects/tangible/ticket/TicketObject.h"
#include "server/zone/managers/planet/PlanetTravelPoint.h"
#include "server/zone/managers/planet/PlanetManager.h"
#include "server/zone/Zone.h"

//#define ENABLE_CITY_TRAVEL_LIMIT

namespace server {
namespace zone {
namespace objects {
namespace creature {
namespace commands {

class BoardShuttleCommand : public QueueCommand {
public:

	static int MAXIMUM_PLAYER_COUNT;
	const int MAXIMUM_POSITION_TRIES = 5;

	BoardShuttleCommand(const String& name, ZoneProcessServer* server);

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const;

private:
	SortedVector<ManagedReference<TicketObject*>> findTicketsInInventory(CreatureObject* creature, PlanetTravelPoint* departurePoint) const;

	void sendTicketSelectionBoxTo(CreatureObject* player, SortedVector<ManagedReference<TicketObject*>> tickets) const;

	Coordinate findRandomizedArrivalPoint(CreatureObject* targetShuttleObject, PlanetManager* planetManager, Zone* arrivalZone, PlanetTravelPoint* arrivalPoint, int tries) const;
};

} // namespace commands
} // namespace creature
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::creature::commands;
