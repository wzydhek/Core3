/*
 * ListGuildsResponseSuiCallback.h
 *
 *  Created on: Nov 4, 2010
 *      Author: crush
 */

#pragma once

#include "server/zone/objects/player/sui/SuiCallback.h"

class ListGuildsResponseSuiCallback : public SuiCallback {
public:
	ListGuildsResponseSuiCallback(ZoneServer* server);

	void run(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args);
};
