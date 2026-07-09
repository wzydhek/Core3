/*
 * PlayerTeachSuiCallback.h
 *
 *  Created on: Mar 13, 2012
 *      Author: katherine
 */

#pragma once

#include "server/zone/objects/player/sui/SuiCallback.h"
#include "server/zone/objects/creature/CreatureObject.h"

class PlayerTeachSuiCallback : public SuiCallback {

public:
	PlayerTeachSuiCallback(ZoneServer* serv);

	void run(CreatureObject* teacher, SuiBox* sui, uint32 eventIndex, Vector<UnicodeString>* args);
};
