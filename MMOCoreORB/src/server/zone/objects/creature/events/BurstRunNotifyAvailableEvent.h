/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "server/zone/objects/creature/CreatureObject.h"

class BurstRunNotifyAvailableEvent : public Task {
	ManagedWeakReference<CreatureObject*> creo;

public:
	BurstRunNotifyAvailableEvent(CreatureObject* cr);

	void run();

};
