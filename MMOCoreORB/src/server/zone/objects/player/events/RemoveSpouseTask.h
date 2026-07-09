
#pragma once

#include "server/zone/objects/player/PlayerObject.h"

class RemoveSpouseTask : public Task {
	ManagedReference<CreatureObject*> creature;

public:
	RemoveSpouseTask(CreatureObject* creatureObject);

	void run();
};
