/*
 * GroupLootChangedSuiCallback.h
 *
 *  Created on: March 1, 2015
 *      Author: Anakis
 */

#pragma once

#include "server/zone/objects/player/sui/SuiCallback.h"

class GroupLootChangedSuiCallback : public SuiCallback {
public:
	GroupLootChangedSuiCallback(ZoneServer* server);

	void run(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args);

};
