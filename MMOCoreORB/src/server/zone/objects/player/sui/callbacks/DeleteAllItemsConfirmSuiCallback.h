/*
 * DeleteAllItemsConfirmSuiCallback.h
 *
 *  Created on: Aug 14, 2011
 *      Author: crush
 */

#pragma once

#include "server/zone/objects/player/sui/SuiCallback.h"
#include "server/zone/objects/building/BuildingObject.h"
#include "server/zone/objects/transaction/TransactionLog.h"
#include "server/zone/objects/ship/PobShipObject.h"

namespace server {
namespace zone {
namespace objects {
namespace player {
namespace sui {
namespace callbacks {

class DeleteAllItemsConfirmSuiCallback : public SuiCallback {
public:
	DeleteAllItemsConfirmSuiCallback(ZoneServer* serv);

	void run(CreatureObject* creature, SuiBox* sui, uint32 eventIndex, Vector<UnicodeString>* args);
};

} // namespace callbacks
} // namespace sui
} // namespace player
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::player::sui::callbacks;
