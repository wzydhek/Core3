/*
 * TicketSelectionSuiCallback.h
 *
 *  Created on: May 19, 2011
 *      Author: crush
 */

#pragma once

#include "server/zone/objects/player/sui/SuiCallback.h"
#include "server/zone/objects/player/sui/listbox/SuiListBox.h"

class TicketSelectionSuiCallback : public SuiCallback {
public:
	TicketSelectionSuiCallback(ZoneServer* serv);

	void run(CreatureObject* player, SuiBox* sui, uint32 eventIndex, Vector<UnicodeString>* args);
};
