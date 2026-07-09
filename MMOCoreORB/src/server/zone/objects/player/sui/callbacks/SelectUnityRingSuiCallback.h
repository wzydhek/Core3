/*
 * SelectUnityRingSuiCallback.h
 *
 *  Created on: 5/3/2014
 *      Author: Klivian
 */

#pragma once

#include "server/zone/objects/player/sui/SuiCallback.h"
#include "server/zone/objects/creature/CreatureObject.h"

class SelectUnityRingSuiCallback : public SuiCallback {

public:
	SelectUnityRingSuiCallback(ZoneServer* serv);

	void run(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args);
};
