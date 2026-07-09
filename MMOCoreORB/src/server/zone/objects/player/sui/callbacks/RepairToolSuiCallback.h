/*
 * RepairToolSuiCallback.h
 *
 *  Created on: Oct 19, 2019
 *      Author: rafalski
 */

#pragma once

#include "server/zone/objects/player/sui/SuiCallback.h"
#include "server/zone/objects/creature/VehicleObject.h"

class RepairToolSuiCallback : public SuiCallback {
public:
	RepairToolSuiCallback(ZoneServer* server);

	void run(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args);
};
