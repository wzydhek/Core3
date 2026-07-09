/*
 * PowerRegulatorSuiCallback.h
 *
 *  Created on: Nov 2, 2012
 *      Author: root
 */

#pragma once

#include "server/zone/objects/player/sui/SuiCallback.h"
#include "server/zone/managers/gcw/GCWManager.h"

class PowerRegulatorSuiCallback : public SuiCallback {

public:
	PowerRegulatorSuiCallback(ZoneServer* server);

	void run(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args);
};
