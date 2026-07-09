/*
 * DroidProgrammingChipSuiCallback.h
 *
 *  Created on: 3/24/2025
 *      Author: Halyn
 */

#pragma once

#include "server/zone/objects/player/sui/SuiCallback.h"

class DroidProgrammingChipSuiCallback : public SuiCallback {
public:
	DroidProgrammingChipSuiCallback(ZoneServer* serv);

	void run(CreatureObject* creature, SuiBox* sui, uint32 eventIndex, Vector<UnicodeString>* args);
};
