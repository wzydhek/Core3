/*
 * FindLostItemsSuiCallback.h
 *
 *  Created on: Aug 15, 2011
 *      Author: crush
 */

#pragma once

#include "server/zone/objects/player/sui/SuiCallback.h"
#include "server/zone/objects/building/BuildingObject.h"
#include "server/zone/managers/structure/StructureManager.h"

class FindLostItemsSuiCallback : public SuiCallback {
public:
	FindLostItemsSuiCallback(ZoneServer* serv);

	void run(CreatureObject* creature, SuiBox* sui, uint32 eventIndex, Vector<UnicodeString>* args);
};
