/*
 * GroupLootPickLooterSuiCallback.h
 *
 *  Created on: March 2, 2015
 *      Author: Anakis
 */

#pragma once

#include "server/zone/objects/player/sui/SuiCallback.h"
#include "server/zone/objects/player/sui/listbox/SuiListBox.h"

class GroupLootPickLooterSuiCallback : public SuiCallback {
public:
	GroupLootPickLooterSuiCallback(ZoneServer* server);

	void run(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args);

};
