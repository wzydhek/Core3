/*
 * GamblingSlotPayoutSuiCallback.h
 *
 *  Created on: 04/29, 2012
 *      Author: Elvaron
 */

#pragma once

#include "server/zone/objects/player/sui/SuiCallback.h"
#include "server/zone/managers/minigames/GamblingManager.h"

class GamblingSlotPayoutSuiCallback : public SuiCallback {
public:
	GamblingSlotPayoutSuiCallback(ZoneServer* server);

	void run(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args);
};
