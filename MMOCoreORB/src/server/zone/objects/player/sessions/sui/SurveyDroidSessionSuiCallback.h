/*
 * SlicingSessionSuiCallback.h
 *
 *	Created on: Mar 5, 2011
 *		Author: polonel
 */

#pragma once

#include "server/zone/objects/player/sui/SuiCallback.h"
#include "server/zone/objects/player/sui/SuiBox.h"

class SurveyDroidSessionSuiCallback : public SuiCallback {
public:
	SurveyDroidSessionSuiCallback(ZoneServer* server);

	void run(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args);
};
