/*
 * DeleteCharactersTask.h
 *
 *  Created on: Jul 3, 2012
 *      Author: swgemu
 */

#pragma once

#include "server/zone/ZoneServer.h"
#include "server/zone/ZoneClientSession.h"
#include "server/zone/managers/player/PlayerManager.h"
#include "server/zone/objects/transaction/TransactionLog.h"

class DeleteCharactersTask : public Task, public Logger {
	SortedVector<uint64> deletedCharacters;
#ifdef WITH_SWGREALMS_API
	String currentPurgeBatchID;
#endif

public:
	DeleteCharactersTask();

	void run();

	void updateDeletedCharacters();
};
