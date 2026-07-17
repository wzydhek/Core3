/*
 * TipBankSuiCallback.h
 *
 *  Created on: 18 jul. 2011
 *      Author: Moncai
 */

#pragma once

#include "server/zone/objects/player/sui/SuiCallback.h"
#include "server/zone/objects/player/PlayerObject.h"
#include "server/chat/ChatManager.h"
#include "server/zone/objects/transaction/TransactionLog.h"

namespace server {
namespace zone {
namespace objects {
namespace player {
namespace sui {
namespace callbacks {

class TipCommandSuiCallback: public SuiCallback {
private:
	ManagedReference<CreatureObject*> targetPlayer;
	int amount;

public:
	TipCommandSuiCallback(ZoneServer* server, CreatureObject* target, int amount);

	void run(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args);
};

} // namespace callbacks
} // namespace sui
} // namespace player
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::player::sui::callbacks;
