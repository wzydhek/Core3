#pragma once

#include "server/zone/objects/player/sui/SuiCallback.h"
#include "server/zone/ZoneServer.h"
#include "server/zone/objects/tangible/firework/components/FireworkShowDataComponent.h"
#include "server/zone/objects/player/sui/callbacks/FireworkShowDelaySelectionSuiCallback.h"
#include "server/zone/objects/player/sui/listbox/SuiListBox.h"
#include "server/zone/objects/player/sui/fireworkdelaybox/SuiFireworkDelayBox.h"

class FireworkShowModifyEventSuiCallback : public SuiCallback {
public:
	FireworkShowModifyEventSuiCallback(ZoneServer* server);

	void run(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args);
};
