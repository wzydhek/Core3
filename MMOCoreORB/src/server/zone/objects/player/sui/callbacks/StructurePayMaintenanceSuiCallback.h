/*
 * StructurePayMaintenanceSuiCallback.h
 *
 *  Created on: Aug 16, 2011
 *      Author: cRush
 */

#pragma once

#include "server/zone/objects/player/sui/SuiCallback.h"
#include "server/zone/objects/creature/CreatureObject.h"
#include "server/zone/objects/structure/StructureObject.h"
#include "server/zone/managers/structure/StructureManager.h"

class StructurePayMaintenanceSuiCallback : public SuiCallback {
public:
	StructurePayMaintenanceSuiCallback(ZoneServer* serv);

	void run(CreatureObject* creature, SuiBox* sui, uint32 eventIndex, Vector<UnicodeString>* args);
};
