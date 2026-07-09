/*
 * InsertPilotIntoShipTask.h
 */

#pragma once

#include "server/zone/objects/creature/CreatureObject.h"
#include "server/zone/SpaceZone.h"
#include "server/zone/objects/ship/PobShipObject.h"
#include "server/zone/objects/player/PlayerObject.h"
#include "templates/params/creature/PlayerArrangement.h"

class InsertPilotIntoShipTask : public Task, public Logger {
	ManagedWeakReference<CreatureObject*> play;
	ManagedWeakReference<ShipObject*> shipObject;

public:
	InsertPilotIntoShipTask(CreatureObject* creo, ShipObject* shipObj);

	void run();
};
