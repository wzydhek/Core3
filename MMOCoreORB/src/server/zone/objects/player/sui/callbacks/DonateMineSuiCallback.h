/*
 * DonateMineSuiCallback.h
 *
 *  Created on: 2024-08-13
 *  Author: Hakry
 */

#pragma once

#include "server/zone/objects/player/sui/SuiCallback.h"
#include "server/zone/managers/gcw/GCWManager.h"

class DonateMineSuiCallback : public SuiCallback {
public:
	DonateMineSuiCallback(ZoneServer* server);

	void run(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args);
};
