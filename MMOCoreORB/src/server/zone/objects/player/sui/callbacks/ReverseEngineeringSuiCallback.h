/*
 * ReverseEngineeringSuiCallback.h
 *
 *  Created on: Jan 25, 2025
 *      Author: Halyn
 */

#pragma once

#include "server/zone/objects/player/sui/SuiCallback.h"
#include "server/zone/objects/ship/components/ShipComponent.h"
#include "server/zone/objects/player/sui/callbacks/NameComponentSuiCallback.h"
#include "server/zone/objects/player/sui/inputbox/SuiInputBox.h"

class ReverseEngineeringSuiCallback : public SuiCallback {
public:
	ReverseEngineeringSuiCallback(ZoneServer* serv);

	void run(CreatureObject* creature, SuiBox* sui, uint32 eventIndex, Vector<UnicodeString>* args);
};
