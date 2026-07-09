/*
 * NameStructureSuiCallback.h
 *
 *  Created on: Aug 9, 2011
 *      Author: crush
 */

#pragma once

#include "server/zone/objects/player/sui/SuiCallback.h"
#include "server/zone/objects/creature/CreatureObject.h"

class NameStructureSuiCallback : public SuiCallback {
public:
	NameStructureSuiCallback(ZoneServer* serv);

	void run(CreatureObject* creature, SuiBox* sui, uint32 eventIndex, Vector<UnicodeString>* args);
};
