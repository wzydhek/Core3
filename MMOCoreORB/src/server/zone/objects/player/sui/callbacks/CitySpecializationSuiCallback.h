/*
 * CitySpecializationSuiCallback.h
 *
 *  Created on: Feb 13, 2012
 *      Author: xyborn
 */

#pragma once

#include "server/zone/objects/player/sui/SuiCallback.h"
#include "server/zone/objects/player/sui/listbox/SuiListBox.h"
#include "server/zone/objects/player/sessions/CitySpecializationSession.h"

class CitySpecializationSuiCallback : public SuiCallback {
public:
	CitySpecializationSuiCallback(ZoneServer* server);

	void run(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args);
};
