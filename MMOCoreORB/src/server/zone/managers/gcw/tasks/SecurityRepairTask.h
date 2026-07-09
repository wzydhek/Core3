#pragma once

#include "server/zone/managers/gcw/GCWManager.h"

class SecurityRepairTask : public Task {

	ManagedReference<TangibleObject*> terminal;
	ManagedReference<GCWManager*> gcwManager;
	ManagedReference<CreatureObject*> creature;
	int count;

public:
	SecurityRepairTask(GCWManager* gcwMan, TangibleObject* term, CreatureObject* player, int cnt);

	void run();
};
