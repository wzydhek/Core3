#pragma once

#include "server/zone/objects/player/sui/SuiCallback.h"
#include "server/zone/objects/tangible/eventperk/LotteryDroid.h"
#include "server/zone/objects/player/sui/messagebox/SuiMessageBox.h"
#include "server/zone/managers/stringid/StringIdManager.h"
#include "server/zone/objects/transaction/TransactionLog.h"
#include "server/zone/objects/player/PlayerObject.h"

namespace server {
namespace zone {
namespace objects {
namespace creature {
namespace sui {

class LotteryDroidSuiCallback : public SuiCallback {
private:
	int optionalArg;
public:
	LotteryDroidSuiCallback(ZoneServer* server, int optArg);

	void run(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args);
};

} // namespace sui
} // namespace creature
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::creature::sui;
