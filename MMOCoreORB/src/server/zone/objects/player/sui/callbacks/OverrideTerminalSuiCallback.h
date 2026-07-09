/*
 * OverrideTerminalSuiCallback.h
 *
 *  Created on: Nov 1, 2012
 *      Author: root
 */

#pragma once

#include "server/zone/objects/player/sui/SuiCallback.h"
#include "server/zone/managers/gcw/GCWManager.h"

class OverrideTerminalSuiCallback : public SuiCallback {

public:
	OverrideTerminalSuiCallback(ZoneServer* server);

	void run(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args);
};
