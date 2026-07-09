/*
 * CloningStoreConfirmSuiCallback.h
 *
 *  Created on: 01/13, 2012
 *      Author: Elvaron
 */

#pragma once

#include "server/zone/objects/player/sui/SuiCallback.h"
#include "server/zone/objects/player/PlayerObject.h"
#include "server/zone/objects/building/BuildingObject.h"
#include "server/zone/objects/transaction/TransactionLog.h"

class CloningStoreSuiCallback : public SuiCallback {
	bool hasCoupon;

public:
	CloningStoreSuiCallback(ZoneServer* server, bool coupon);

	void run(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args);
};
