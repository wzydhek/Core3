/*
 * StructureStatusSuiCallback.h
 *
 *  Created on: Aug 15, 2011
 *      Author: crush
 */

#pragma once

#include "server/zone/objects/player/sui/SuiCallback.h"
#include "server/zone/objects/structure/StructureObject.h"
#include "server/zone/managers/gcw/GCWManager.h"

class StructureStatusSuiCallback : public SuiCallback {
public:
	StructureStatusSuiCallback(ZoneServer* serv);

	void run(CreatureObject* creature, SuiBox* sui, uint32 eventIndex, Vector<UnicodeString>* args);
};
