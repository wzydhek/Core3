/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "server/zone/objects/creature/CreatureObject.h"
#include "server/zone/objects/tangible/firework/FireworkObject.h"

class FireworkLaunchEvent : public Task {
	ManagedWeakReference<FireworkObject*> firework;
	ManagedWeakReference<CreatureObject*> player;
	int removeDelay;

public:
	FireworkLaunchEvent(CreatureObject* player, FireworkObject* firework, int removeDelay);

	void run();
};
