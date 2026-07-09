/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once


#include "server/zone/objects/creature/CreatureObject.h"
#include "server/zone/objects/tangible/firework/FireworkObject.h"
#include "server/zone/objects/tangible/firework/components/FireworkShowDataComponent.h"
#include "server/zone/objects/staticobject/StaticObject.h"
#include "FireworkRemoveEvent.h"
#include "server/zone/Zone.h"
#include "server/zone/ZoneServer.h"

class FireworkShowLaunchFireworkEvent : public Task {
	Reference<FireworkShowDataComponent*> fireworkShowData;
	ManagedReference<FireworkObject*> fireworkShow;
	ManagedWeakReference<CreatureObject*> player;
	ManagedReference<StaticObject*> worldFireworkShow;
	int removeDelay;

public:
	FireworkShowLaunchFireworkEvent(CreatureObject* player, FireworkObject* fireworkShow, FireworkShowDataComponent* fireworkShowData, StaticObject* worldFireworkShow);

	void run();
};
