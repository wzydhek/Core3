/*
 * ReplaceFlashSpeederSuiCallback.h
 *
 *  Created on: 8/3/2014
 *      Author: Klivian
 */

#pragma once

#include "server/zone/objects/player/sui/SuiCallback.h"
#include "server/zone/objects/transaction/TransactionLog.h"

namespace server {
namespace zone {
namespace objects {
namespace player {
namespace sui {
namespace callbacks {

class ReplaceFlashSpeederSuiCallback : public SuiCallback {

public:

	enum {
		FLASH_SPEEDER_COST = 20000
	};

	ReplaceFlashSpeederSuiCallback(ZoneServer* server);

	void run(CreatureObject* player, SuiBox* sui, uint32 eventIndex, Vector<UnicodeString>* args);
};

} // namespace callbacks
} // namespace sui
} // namespace player
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::player::sui::callbacks;
