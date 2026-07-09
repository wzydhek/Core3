/*
 * ConfirmVeteranSuiCallback.h
 *
 *  Created on: 5/30/2014
 *      Author: Klivian
 */

#pragma once

#include "server/zone/objects/player/sui/SuiCallback.h"

class ConfirmVeteranRewardSuiCallback : public SuiCallback {

public:
	ConfirmVeteranRewardSuiCallback(ZoneServer* serv);

	void run(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args);
};
