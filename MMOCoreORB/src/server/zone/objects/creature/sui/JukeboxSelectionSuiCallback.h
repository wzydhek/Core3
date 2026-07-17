#pragma once

#include "server/zone/objects/player/sui/SuiCallback.h"
#include "server/zone/objects/tangible/eventperk/Jukebox.h"
#include "server/zone/managers/player/JukeboxSong.h"
#include "server/zone/objects/player/sui/listbox/SuiListBox.h"
#include "server/zone/managers/player/PlayerManager.h"

namespace server {
namespace zone {
namespace objects {
namespace creature {
namespace sui {

class JukeboxSelectionSuiCallback : public SuiCallback {
public:
	JukeboxSelectionSuiCallback(ZoneServer* server);

	void run(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args);
};

} // namespace sui
} // namespace creature
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::creature::sui;
