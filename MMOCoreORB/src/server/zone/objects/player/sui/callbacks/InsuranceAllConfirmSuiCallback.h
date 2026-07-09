/*
 * InsuranceAllConfirmSuiCallback.h
 *
 *  Created on: 01/13, 2012
 *      Author: Elvaron
 */

#pragma once

#include "server/zone/objects/player/sui/SuiCallback.h"
#include "server/zone/managers/player/PlayerManager.h"
#include "templates/params/OptionBitmask.h"
#include "server/zone/objects/transaction/TransactionLog.h"

class InsuranceAllConfirmSuiCallback : public SuiCallback {
public:
	InsuranceAllConfirmSuiCallback(ZoneServer* server);

	void run(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args);
};
