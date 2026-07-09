/*
 * CityTreasuryWithdrawalSuiCallback.h
 *
 *  Created on: Feb 13, 2012
 *      Author: xyborn
 */

#pragma once

#include "server/zone/objects/player/sui/SuiCallback.h"
#include "server/zone/objects/player/sessions/CityTreasuryWithdrawalSession.h"

class CityTreasuryWithdrawalSuiCallback : public SuiCallback {
public:
	CityTreasuryWithdrawalSuiCallback(ZoneServer* server);

	void run(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args);
};
