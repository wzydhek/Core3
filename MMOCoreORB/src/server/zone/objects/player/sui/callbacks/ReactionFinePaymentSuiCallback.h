#pragma once

#include "server/zone/objects/player/sui/SuiCallback.h"
#include "server/zone/objects/player/PlayerObject.h"
#include "server/zone/objects/transaction/TransactionLog.h"

class ReactionFinePaymentSuiCallback : public SuiCallback {

public:

	ReactionFinePaymentSuiCallback(ZoneServer* server);

	void run(CreatureObject* creature, SuiBox* sui, uint32 eventIndex, Vector<UnicodeString>* args);
};
