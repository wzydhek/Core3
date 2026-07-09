/*
 * JamUplinkSuiCallback.h
 *
 *  Created on: Oct 31, 2012
 *      Author: root
 */

#pragma once

#include "server/zone/objects/player/sui/SuiCallback.h"
#include "server/zone/objects/scene/SceneObjectType.h"
#include "server/zone/managers/gcw/GCWManager.h"

class JamUplinkSuiCallback : public SuiCallback {
public:
	JamUplinkSuiCallback(ZoneServer* server);

	void run(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args);
};
