/*
 * SelectVeteranSuiCallback.h
 *
 *  Created on: 5/23/2014
 *      Author: Klivian
 */

#pragma once

#include "server/zone/objects/player/sui/SuiCallback.h"
#include "server/zone/objects/creature/CreatureObject.h"

class SelectVeteranRewardSuiCallback : public SuiCallback {

public:
	SelectVeteranRewardSuiCallback(ZoneServer* serv);

	void run(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args);
};
