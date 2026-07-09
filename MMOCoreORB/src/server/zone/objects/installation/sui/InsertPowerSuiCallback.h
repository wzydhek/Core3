/*
 * InsertPowerSuiCallback.h
 *
 *  Created on: may 22, 2012
 *      Author: kyle
 */

#pragma once

#include "server/zone/objects/installation/InstallationObject.h"
#include "server/zone/objects/player/sui/SuiCallback.h"
#include "server/zone/objects/player/sui/SuiBox.h"
#include "server/zone/managers/resource/ResourceManager.h"

class InsertPowerSuiCallback : public SuiCallback {
public:
	InsertPowerSuiCallback(ZoneServer* server);

	void run(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args);

};
