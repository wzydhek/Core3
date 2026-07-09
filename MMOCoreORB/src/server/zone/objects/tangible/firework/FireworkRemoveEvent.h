/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "server/zone/objects/creature/CreatureObject.h"
#include "server/zone/objects/staticobject/StaticObject.h"

class FireworkRemoveEvent : public Task {
	ManagedReference<StaticObject*> firework;
	ManagedReference<CreatureObject*> player;

public:
	FireworkRemoveEvent(CreatureObject* player, StaticObject* firework);

	void run();
};
