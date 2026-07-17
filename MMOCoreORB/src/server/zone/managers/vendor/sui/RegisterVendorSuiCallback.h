/*
 * RegisterVendorSuiCallback.h
 *
 *  Created on: May 1, 2011
 *      Author: polonel
 */

#pragma once

#include "server/zone/objects/player/sui/SuiCallback.h"
#include "server/zone/managers/vendor/VendorManager.h"

namespace server {
namespace zone {
namespace managers {
namespace vendor {
namespace sui {

class RegisterVendorSuiCallback : public SuiCallback {
public:
	RegisterVendorSuiCallback(ZoneServer* server);

	void run(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args);
};

} // namespace sui
} // namespace vendor
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::vendor::sui;
