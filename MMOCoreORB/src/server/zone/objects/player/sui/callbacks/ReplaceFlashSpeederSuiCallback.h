/*
 * ReplaceFlashSpeederSuiCallback.h
 *
 *  Created on: 8/3/2014
 *      Author: Klivian
 */

#pragma once

#include "server/zone/objects/player/sui/SuiCallback.h"
#include "server/zone/objects/transaction/TransactionLog.h"

class ReplaceFlashSpeederSuiCallback : public SuiCallback {

public:

	enum {
		FLASH_SPEEDER_COST = 20000
	};

	ReplaceFlashSpeederSuiCallback(ZoneServer* server);

	void run(CreatureObject* player, SuiBox* sui, uint32 eventIndex, Vector<UnicodeString>* args);
};
