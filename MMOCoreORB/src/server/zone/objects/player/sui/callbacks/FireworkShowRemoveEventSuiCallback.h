#pragma once

#include "server/zone/objects/tangible/firework/components/FireworkShowMenuComponent.h"
#include "server/zone/objects/player/sui/SuiCallback.h"
#include "server/zone/objects/tangible/firework/components/FireworkShowDataComponent.h"
#include "server/zone/objects/player/sui/listbox/SuiListBox.h"

class FireworkShowRemoveEventSuiCallback : public SuiCallback {
public:
	FireworkShowRemoveEventSuiCallback(ZoneServer* server);

	void run(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args);
};
