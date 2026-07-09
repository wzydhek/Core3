/*
 * HQDefenseStatusCallback.h
 *
 *  Created on: Oct 27, 2012
 *      Author: root
 */

#pragma once

#include "server/zone/objects/player/sui/SuiCallback.h"
#include "server/zone/managers/gcw/GCWManager.h"

class HQDefenseStatusSuiCallback : public SuiCallback {
public:
	HQDefenseStatusSuiCallback(ZoneServer* server);

	void run(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args);
};
