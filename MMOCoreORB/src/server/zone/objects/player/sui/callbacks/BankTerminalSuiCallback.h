/*
 * BankTerminalSuiCallback.h
 *
 * Created on: October 13, 2013
 * by: zaphod
 */

#pragma once

#include "server/zone/objects/player/sui/SuiCallback.h"
#include "server/zone/objects/creature/CreatureObject.h"

class BankTerminalSuiCallback : public SuiCallback {
public:
	BankTerminalSuiCallback(ZoneServer* serv);

	void run(CreatureObject* player, SuiBox* sui, uint32 eventIndex, Vector<UnicodeString>* args);
};
