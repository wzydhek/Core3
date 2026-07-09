/*
 * CloningRequestConfirmSuiCallback.h
 *
 *  Created on: 01/13, 2012
 *      Author: Elvaron
 */

#pragma once

#include "server/zone/objects/player/sui/SuiCallback.h"
#include "server/zone/objects/player/sui/listbox/SuiListBox.h"
#include "server/zone/managers/player/PlayerManager.h"

class CloningRequestSuiCallback : public SuiCallback {
	int typeofdeath;

public:
	CloningRequestSuiCallback(ZoneServer* server, int tod);

	void run(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args);
};
