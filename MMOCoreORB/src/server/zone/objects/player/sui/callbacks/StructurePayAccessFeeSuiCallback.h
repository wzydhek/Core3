/*
 * StructurePayAccessFeeSuiCallback.h
 *
 *  Created on: June 2, 2012
 *      Author: Kyle
 */

#pragma once

#include "server/zone/objects/player/sui/SuiCallback.h"
#include "server/zone/objects/building/BuildingObject.h"

class StructurePayAccessFeeSuiCallback: public SuiCallback {

public:
	StructurePayAccessFeeSuiCallback(ZoneServer* serv);

	void run(CreatureObject* player, SuiBox* sui, uint32 eventIndex, Vector<UnicodeString>* args);
};
