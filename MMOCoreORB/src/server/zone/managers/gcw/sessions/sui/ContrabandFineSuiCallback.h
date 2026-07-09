/*
 * ContrabandFineSuiCallback.h
 *
 *  Created on: nov 30, 2016
 *      Author: loshult
 */

#pragma once

#include "server/zone/objects/player/sui/SuiCallback.h"
#include "server/zone/managers/gcw/sessions/ContrabandScanSession.h"

class ContrabandFineSuiCallback : public SuiCallback {
public:
	ContrabandFineSuiCallback(ZoneServer* server);

	void run(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args);
};
