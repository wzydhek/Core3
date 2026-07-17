/*
 * CreateVendorSuiCallback.h
 *
 *  Created on: Mar 18, 2011
 *      Author: polonel
 */

#pragma once

#include "server/zone/objects/player/sui/SuiCallback.h"
#include "server/zone/objects/player/sui/listbox/SuiListBox.h"
#include "server/zone/objects/player/sessions/vendor/CreateVendorSession.h"

namespace server {
namespace zone {
namespace objects {
namespace player {
namespace sessions {
namespace vendor {
namespace sui {

class CreateVendorSuiCallback : public SuiCallback {
public:
	CreateVendorSuiCallback(ZoneServer* server);

	void run(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args);
};

} // namespace sui
} // namespace vendor
} // namespace sessions
} // namespace player
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::player::sessions::vendor::sui;
