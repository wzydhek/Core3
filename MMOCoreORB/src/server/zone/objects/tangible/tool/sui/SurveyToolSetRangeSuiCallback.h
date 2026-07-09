/*
 * SurveyToolSetRangeSuiCallback.h
 *
 *  Created on: Nov 3, 2010
 *      Author: crush
 */

#pragma once

#include "server/zone/objects/tangible/tool/SurveyTool.h"
#include "server/zone/objects/player/sui/SuiCallback.h"

class SurveyToolSetRangeSuiCallback : public SuiCallback {
public:
	SurveyToolSetRangeSuiCallback(ZoneServer* server);

	void run(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args);
};
