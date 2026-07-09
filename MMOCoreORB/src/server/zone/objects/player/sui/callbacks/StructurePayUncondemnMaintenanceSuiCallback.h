/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "server/zone/objects/player/sui/SuiCallback.h"
#include "server/zone/managers/credit/CreditManager.h"

class StructurePayUncondemnMaintenanceSuiCallback : public SuiCallback {
public:
	StructurePayUncondemnMaintenanceSuiCallback(ZoneServer* serv);

	void run(CreatureObject* creature, SuiBox* sui, uint32 eventIndex, Vector<UnicodeString>* args);
};
