#pragma once

#include "server/zone/objects/player/sui/SuiCallback.h"
#include "server/zone/objects/tangible/eventperk/Jukebox.h"
#include "server/zone/managers/player/JukeboxSong.h"
#include "server/zone/objects/player/sui/listbox/SuiListBox.h"
#include "server/zone/managers/player/PlayerManager.h"

class JukeboxSelectionSuiCallback : public SuiCallback {
public:
	JukeboxSelectionSuiCallback(ZoneServer* server);

	void run(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args);
};
