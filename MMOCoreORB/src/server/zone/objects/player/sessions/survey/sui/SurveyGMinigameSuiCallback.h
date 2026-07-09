/*
 * SurveyGMinigameSuiCallback.h
 *
 *  Created on: may 22, 2012
 *      Author: kyle
 */

#pragma once

#include "server/zone/objects/player/sui/SuiCallback.h"
#include "server/zone/objects/player/sessions/survey/SurveySession.h"

class SurveyGMinigameSuiCallback : public SuiCallback {
public:
	SurveyGMinigameSuiCallback(ZoneServer* server);

	void run(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args);
};
