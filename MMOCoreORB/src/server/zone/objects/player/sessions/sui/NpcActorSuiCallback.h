/*
 * NpcActorSuiCallback.h
 *
 * Created: 2024-04-22
 * By: Hakry
 *
*/

#pragma once

#include "server/zone/objects/player/sui/SuiCallback.h"
#include "server/zone/objects/player/sui/listbox/SuiListBox.h"
#include "server/zone/objects/tangible/deed/eventperk/EventPerkDeed.h"
#include "server/zone/objects/player/sessions/NpcActorCreationSession.h"

namespace server {
namespace zone {
namespace objects {
namespace player {
namespace sessions {
namespace sui {

class NpcActorSuiCallback : public SuiCallback {
public:
	NpcActorSuiCallback(ZoneServer* server);

	void run(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args);

	void clearSession(CreatureObject* player);
};

} // namespace sui
} // namespace sessions
} // namespace player
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::player::sessions::sui;
