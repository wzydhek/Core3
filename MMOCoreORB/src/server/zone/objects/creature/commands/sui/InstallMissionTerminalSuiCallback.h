/*
 * InstallMissionTerminalSuiCallback.h
 *
 *  Created on: Apr 25, 2012
 *      Author: TragD
 */

#pragma once

#include "server/zone/objects/player/sui/SuiCallback.h"

class InstallMissionTerminalSuiCallback : public SuiCallback {
public:
	InstallMissionTerminalSuiCallback(ZoneServer* server);

	void run(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args);
};
