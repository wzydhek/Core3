
#pragma once

#include "server/zone/objects/creature/CreatureObject.h"
#include "server/zone/objects/creature/ai/AiAgent.h"
#include "server/zone/objects/group/GroupObject.h"
#include "server/zone/objects/player/PlayerObject.h"

class RemovePetsFromGroupTask : public Task {
	ManagedReference<CreatureObject*> player;
	ManagedReference<GroupObject*> group;
public:
	RemovePetsFromGroupTask(CreatureObject* creo, GroupObject* grp);

	void run();
};
