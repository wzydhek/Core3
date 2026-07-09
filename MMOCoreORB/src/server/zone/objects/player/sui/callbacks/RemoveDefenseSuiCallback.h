/*
 * RemoveDefenseSuiCallback.h
 *
 *  Created on: Dec 3, 2012
 *      Author: root
 */

#pragma once

#include "server/zone/objects/player/sui/SuiCallback.h"
#include "server/zone/managers/gcw/GCWManager.h"

class RemoveDefenseSuiCallback : public SuiCallback {
private:
	uint64 deed;
public:
	RemoveDefenseSuiCallback(ZoneServer* server, uint64 deedID);

	void run(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args);
};
