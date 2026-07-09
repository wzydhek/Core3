/*
 * NameComponentSuiCallback.h
 *
 *  Created on: Jan 25, 2025
 *  	Author: Halyn
 */

#pragma once

#include "server/zone/objects/player/sui/SuiCallback.h"
#include "server/zone/objects/creature/CreatureObject.h"
#include "server/zone/ZoneProcessServer.h"
#include "server/zone/managers/name/NameManager.h"
#include "server/zone/objects/player/sui/inputbox/SuiInputBox.h"

class NameComponentSuiCallback : public SuiCallback {
public:
	NameComponentSuiCallback(ZoneServer* serv);

	void run(CreatureObject* player, SuiBox* sui, uint32 eventIndex, Vector<UnicodeString>* args);
};
