/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "server/zone/objects/creature/CreatureObject.h"

class DroidCommandNotifyAvailableEvent : public Task {
	ManagedWeakReference<CreatureObject*> creo;

public:
	DroidCommandNotifyAvailableEvent(CreatureObject* cr);

	void run();

};
