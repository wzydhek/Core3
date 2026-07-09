/*
 * StructureAssignDroidSuiCallback.h
 */

#pragma once

#include "server/zone/objects/player/sui/SuiCallback.h"
#include "server/zone/objects/player/sui/listbox/SuiListBox.h"
#include "server/zone/objects/creature/ai/DroidObject.h"

class StructureAssignDroidSuiCallback: public SuiCallback {

public:
	StructureAssignDroidSuiCallback(ZoneServer* serv);

	void run(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args);
};
