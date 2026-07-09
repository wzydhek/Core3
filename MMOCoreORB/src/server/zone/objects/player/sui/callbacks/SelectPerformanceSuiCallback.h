#pragma once

#include "server/zone/objects/player/sui/SuiCallback.h"
#include "server/zone/objects/creature/CreatureObject.h"

class SelectPerformanceSuiCallback : public SuiCallback {
	int performanceType;
	bool bandCommand;
public:
	SelectPerformanceSuiCallback(ZoneServer* server, int type, bool bandCmd);

	void run(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args);
};
