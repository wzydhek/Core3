/*
 * DestroyCommandSuiCallback.h
 *
 *  Created on: Nov 3, 2010
 *      Author: crush
 */

#pragma once

#include "server/zone/objects/player/sui/SuiCallback.h"

class DestroyCommandSuiCallback : public SuiCallback {
public:
	DestroyCommandSuiCallback(ZoneServer* server);

	void run(CreatureObject* creature, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args);
};
