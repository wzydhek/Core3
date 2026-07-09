/*
 * InsertGroupMembertIntoShipTask.h
 */

#pragma once

#include "server/zone/objects/creature/CreatureObject.h"
#include "server/zone/objects/ship/ShipObject.h"
#include "server/zone/objects/ship/PobShipObject.h"
#include "server/zone/objects/ship/MultiPassengerShipObject.h"
#include "server/zone/SpaceZone.h"

class InsertGroupMembertIntoShipTask : public Task, public Logger {
	ManagedWeakReference<ShipObject*> shipObj;
	uint64 memberID;
	int playerArrangement;

public:
	InsertGroupMembertIntoShipTask(ShipObject* shipObj, uint64 memID, int arrangement);

	void run();
};
