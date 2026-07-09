/*
 * DestroyStructureRequestSuiCallback.h
 *
 *  Created on: Jun 22, 2011
 *      Author: crush
 */

#pragma once

#include "server/zone/objects/player/sui/SuiCallback.h"
#include "server/zone/objects/player/sessions/DestroyStructureSession.h"

class DestroyStructureRequestSuiCallback : public SuiCallback {
public:
	DestroyStructureRequestSuiCallback(ZoneServer* serv);

	void run(CreatureObject* player, SuiBox* sui, uint32 eventIndex, Vector<UnicodeString>* args);
};
