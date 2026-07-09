/*
 * LoadStimpackSuiCallback.h
 *
 */

#pragma once

#include "server/zone/objects/player/sui/SuiCallback.h"
#include "server/zone/objects/player/sui/listbox/SuiListBox.h"
#include "server/zone/objects/tangible/pharmaceutical/StimPack.h"
#include "server/zone/objects/tangible/components/droid/DroidStimpackModuleDataComponent.h"
#include "server/zone/objects/creature/ai/DroidObject.h"

class LoadStimpackSuiCallback : public SuiCallback {
public:
	LoadStimpackSuiCallback(ZoneServer* server);

	void run(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args);

};
