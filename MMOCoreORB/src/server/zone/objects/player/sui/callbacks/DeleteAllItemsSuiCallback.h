/*
 * DeleteAllItemsSuiCallback.h
 *
 *  Created on: Aug 14, 2011
 *      Author: crush
 */

#pragma once

#include "server/zone/objects/player/sui/SuiCallback.h"
#include "server/zone/objects/player/PlayerObject.h"
#include "server/zone/objects/player/sui/callbacks/DeleteAllItemsConfirmSuiCallback.h"

class DeleteAllItemsSuiCallback : public SuiCallback {
public:
	DeleteAllItemsSuiCallback(ZoneServer* serv);

	void run(CreatureObject* creature, SuiBox* sui, uint32 eventIndex, Vector<UnicodeString>* args);
};
