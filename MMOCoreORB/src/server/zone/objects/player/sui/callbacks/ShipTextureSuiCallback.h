/*
 * ShipTextureSuiCallback.h
 *
 *  Created on: 7/16/2023
 *      Author: Halyn
 */

#pragma once

#include "server/zone/objects/player/sui/SuiCallback.h"
#include "server/zone/objects/creature/CreatureObject.h"

class ShipTextureSuiCallback : public SuiCallback {
public:
	ShipTextureSuiCallback(ZoneServer* serv);

	void run(CreatureObject* creature, SuiBox* sui, uint32 eventIndex, Vector<UnicodeString>* args);
};
