/*
 * RespawnCreatureTask.h
 *
 *  Created on: 03/08/2010
 *      Author: victor
 */

#pragma once

#include "server/zone/objects/creature/ai/AiAgent.h"
#include "server/zone/Zone.h"

class RespawnCreatureTask : public Task {
	ManagedReference<AiAgent*> creature;
	Zone* zone;
	int level;

public:
	RespawnCreatureTask(AiAgent* cr, Zone* zn, int level);

	void run();
};
