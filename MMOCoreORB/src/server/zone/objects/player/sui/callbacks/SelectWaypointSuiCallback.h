/*
 * SelectDroidEffectSuiCallback.h
 *
 *  Created on: 11/28/2014
 *      Author: Klivian
 */

#pragma once

#include "server/zone/objects/player/sui/SuiCallback.h"
#include "server/zone/objects/tangible/components/droid/DroidMerchantModuleDataComponent.h"
#include "server/zone/objects/player/sui/listbox/SuiListBox.h"

class SelectWaypointSuiCallback : public SuiCallback, public Logger {

	Reference<DroidMerchantModuleDataComponent*> module;
	int slotIndex;

public:
	SelectWaypointSuiCallback(ZoneServer* serv, DroidMerchantModuleDataComponent* module);

	void run(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args);
};
