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

namespace server {
namespace zone {
namespace managers {
namespace vendor {
namespace sui {

class DestroyVendorSuiCallback : public SuiCallback {
public:
	DestroyVendorSuiCallback(ZoneServer* server);

	void run(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args);
};

} // namespace sui
} // namespace vendor
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::vendor::sui;
