/*
 * LightsaberCrystalTuneSuiCallback.h
 *
 *  Created on: Apr 12, 2012
 *      Author: katherine
 */

#pragma once

#include "server/zone/objects/player/sui/SuiCallback.h"

class LightsaberCrystalTuneSuiCallback: public SuiCallback {

public:
	LightsaberCrystalTuneSuiCallback(ZoneServer* serv);

	void run(CreatureObject* creature, SuiBox* sui, uint32 eventIndex, Vector<UnicodeString>* args);
};
