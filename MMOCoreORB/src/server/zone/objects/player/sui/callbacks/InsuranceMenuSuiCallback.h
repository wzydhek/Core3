/*
 * InsuranceMenuSuiCallback.h
 *
 *  Created on: 01/13, 2012
 *      Author: Elvaron
 */

#pragma once

#include "server/zone/objects/player/sui/SuiCallback.h"
#include "server/zone/objects/player/sui/messagebox/SuiMessageBox.h"
#include "server/zone/objects/player/sui/listbox/SuiListBox.h"
#include "server/zone/objects/player/sui/callbacks/InsuranceAllConfirmSuiCallback.h"
#include "templates/params/OptionBitmask.h"
#include "server/zone/objects/transaction/TransactionLog.h"

class InsuranceMenuSuiCallback : public SuiCallback {
public:
	InsuranceMenuSuiCallback(ZoneServer* server);

	void run(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args);
};
