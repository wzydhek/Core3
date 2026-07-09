/*
 * DestroyVendorSuiCallback.h
 *
 *  Created on: Mar 25, 2011
 *      Author: polonel
 */

#pragma once

#include "server/zone/objects/player/sui/SuiCallback.h"
#include "server/zone/managers/vendor/VendorManager.h"
#include "server/zone/objects/transaction/TransactionLog.h"

class DestroyVendorSuiCallback : public SuiCallback {
public:
	DestroyVendorSuiCallback(ZoneServer* server);

	void run(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args);
};
