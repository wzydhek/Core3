/*
 * GamblingSlotSuiCallback.h
 *
 *  Created on: 04/29, 2012
 *      Author: Elvaron
 */

#pragma once

#include "server/zone/objects/player/sui/SuiCallback.h"
#include "server/zone/managers/minigames/GamblingManager.h"

class GamblingSlotSuiCallback : public SuiCallback {
public:
	GamblingSlotSuiCallback(ZoneServer* server);

	void run(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args);
};
