/*
 * FindSessionSuiCallback.h
 *
 *  Created on: Jun 24, 2011
 *      Author: polonel
 */

#pragma once

#include "server/zone/objects/player/sui/SuiCallback.h"
#include "server/zone/objects/player/sessions/admin/PlayerManagementSession.h"
#include "server/zone/objects/creature/CreatureObject.h"
#include "server/zone/managers/player/PlayerManager.h"

class PlayerManagementSessionSuiCallback : public SuiCallback {
public:
	PlayerManagementSessionSuiCallback(ZoneServer* server);

	void run(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args);

	void runAccountInfo(CreatureObject* player, SuiBox* suiBox, bool cancelPressed, Vector<UnicodeString>* args);

	uint32 getPlayerGalaxyID(CreatureObject* player, SuiListBox* listBox, int index, String& galaxyName);

	void runDurationCallback(CreatureObject* player, SuiBox* suiBox, bool cancelPressed, Vector<UnicodeString>* args);

	void runReasonCallback(CreatureObject* player, SuiBox* suiBox, bool cancelPressed, Vector<UnicodeString>* args);

	void runSummaryCallback(CreatureObject* player, SuiBox* suiBox, bool cancelPressed, Vector<UnicodeString>* args);

	void runUnbanSummaryCallback(CreatureObject* player, SuiBox* suiBox, bool cancelPressed, Vector<UnicodeString>* args);
};
