/*
 * FindSessionSuiCallback.h
 *
 *  Created on: Jun 24, 2011
 *      Author: polonel
 */

#pragma once

#include "server/zone/objects/player/sui/SuiCallback.h"
#include "server/zone/objects/player/sessions/FindSession.h"

class FindSessionSuiCallback : public SuiCallback {
public:
	FindSessionSuiCallback(ZoneServer* server);

	void run(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args);
};
