/*
 * SlicingSessionSuiCallback.h
 *
 *  Created on: Mar 5, 2011
 *      Author: polonel
 */

#pragma once

#include "server/zone/objects/player/sui/SuiCallback.h"
#include "server/zone/objects/player/sessions/SlicingSession.h"

class SlicingSessionSuiCallback : public SuiCallback {
public:
	SlicingSessionSuiCallback(ZoneServer* server);

	void run(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args);
};
