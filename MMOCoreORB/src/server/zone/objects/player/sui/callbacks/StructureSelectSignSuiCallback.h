/*
 * StructureSelectSignSuiCallback.h
 *
 *  Created on: March 9, 2014
 *      Author: Klivian
 */

#pragma once

#include "server/zone/objects/player/sui/SuiCallback.h"
#include "server/zone/objects/creature/CreatureObject.h"
#include "server/zone/objects/structure/StructureObject.h"
#include "server/zone/managers/structure/StructureManager.h"

class StructureSelectSignSuiCallback : public SuiCallback {
public:
	StructureSelectSignSuiCallback(ZoneServer* serv);

	void run(CreatureObject* creature, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args);
};
