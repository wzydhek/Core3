/*
 * StructureSetAccessFeeSuiCallback.h
 *
 *  Created on: Feb 5, 2012
 *      Author: Kyle
 */

#pragma once

#include "server/zone/objects/player/sui/SuiCallback.h"
#include "server/zone/objects/creature/CreatureObject.h"

class StructureSetAccessFeeSuiCallback : public SuiCallback {

public:
	StructureSetAccessFeeSuiCallback(ZoneServer* serv);

	void run(CreatureObject* creature, SuiBox* sui, uint32 eventIndex, Vector<UnicodeString>* args);
};
