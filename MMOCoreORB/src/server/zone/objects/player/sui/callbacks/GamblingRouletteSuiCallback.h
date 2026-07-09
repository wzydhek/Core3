/*
 * GamblingRouletteSuiCallback.h
 *
 *  Created on: 04/29, 2012
 *      Author: Elvaron
 */

#pragma once

#include "server/zone/objects/player/sui/SuiCallback.h"
#include "server/zone/managers/minigames/GamblingManager.h"

class GamblingRouletteSuiCallback : public SuiCallback {
public:
	GamblingRouletteSuiCallback(ZoneServer* server);

	void run(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args);
};
