/*
 * DonateDefenseSuiCallback.h
 *
 *  Created on: Nov 30, 2012
 *      Author: root
 */

#pragma once

#include "server/zone/objects/player/sui/SuiCallback.h"
#include "server/zone/managers/gcw/GCWManager.h"

class DonateDefenseSuiCallback : public SuiCallback {
public:
	DonateDefenseSuiCallback(ZoneServer* server);

	void run(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args);
};
