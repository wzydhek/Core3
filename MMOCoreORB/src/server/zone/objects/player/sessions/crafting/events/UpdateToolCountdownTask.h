
/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "engine/engine.h"
#include "server/zone/objects/creature/CreatureObject.h"

class UpdateToolCountdownTask : public Task {
	ManagedWeakReference<TangibleObject* > craftTool;
	ManagedWeakReference<CreatureObject* > player;
	int timeLeft;

public:
	UpdateToolCountdownTask(CreatureObject* pl, TangibleObject* tool, int time);

	void run();
};
