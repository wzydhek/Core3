/*
 * AdBarkingPhraseSuiCallback.h
 *
 *  Created on: July 5, 2012
 *      Author: Kyle
 */

#pragma once

#include "server/zone/objects/player/sui/SuiCallback.h"
#include "server/zone/objects/player/sessions/vendor/VendorAdBarkingSession.h"
#include "server/zone/objects/player/sui/listbox/SuiListBox.h"
#include "server/zone/managers/name/NameManager.h"

namespace server {
namespace zone {
namespace objects {
namespace player {
namespace sui {
namespace callbacks {

class AdBarkingPhraseSuiCallback : public SuiCallback {
public:
	AdBarkingPhraseSuiCallback(ZoneServer* serv);

	void run(CreatureObject* creature, SuiBox* sui, uint32 eventIndex, Vector<UnicodeString>* args);

	void handleSelectPhrase(VendorAdBarkingSession* session, CreatureObject* creature, SuiBox* sui, bool cancelPressed, Vector<UnicodeString>* args);

	void handleCustomMessage(VendorAdBarkingSession* session, CreatureObject* creature, SuiBox* sui, bool cancelPressed, Vector<UnicodeString>* args);

	void handleSelectMood(VendorAdBarkingSession* session, CreatureObject* creature, SuiBox* sui, bool cancelPressed, Vector<UnicodeString>* args);

	void handleSelectAnimation(VendorAdBarkingSession* session, CreatureObject* creature, SuiBox* sui, bool cancelPressed, Vector<UnicodeString>* args);
};

} // namespace callbacks
} // namespace sui
} // namespace player
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::player::sui::callbacks;
