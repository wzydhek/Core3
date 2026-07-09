#pragma once

#include "server/zone/objects/player/sui/SuiCallback.h"
#include "server/zone/objects/player/sui/listbox/SuiListBox.h"
#include "server/zone/objects/tangible/misc/PlantObject.h"
#include "server/zone/managers/crafting/CraftingManager.h"
#include "server/zone/objects/resource/ResourceContainer.h"

class GrowablePlantSuiCallback : public SuiCallback {
public:
	GrowablePlantSuiCallback(ZoneServer* server);

	void run(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args);
};
