/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "server/zone/objects/creature/CreatureObject.h"

class GallopNotifyAvailableEvent : public Task {
	ManagedWeakReference<CreatureObject*> creo;

public:
	GallopNotifyAvailableEvent(CreatureObject* cr);

	void run();

};
