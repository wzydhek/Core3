/*
 * ProposeUnitySuiCallback.h
 *
 *  Created on: 5/2/2014
 *      Author: Klivian
 */

#pragma once

#include "server/zone/objects/player/sui/SuiCallback.h"
#include "server/zone/objects/creature/CreatureObject.h"

class ProposeUnitySuiCallback : public SuiCallback {

public:

	ProposeUnitySuiCallback(ZoneServer* server);

	void run(CreatureObject* creature, SuiBox* sui, uint32 eventIndex, Vector<UnicodeString>* args);
};
