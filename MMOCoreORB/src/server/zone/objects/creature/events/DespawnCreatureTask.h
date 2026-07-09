/*
 * DespawnCreatureTask.h
 *
 *  Created on: 12/07/2010
 *      Author: victor
 */

#pragma once

#include "server/zone/objects/creature/ai/AiAgent.h"
#include "server/zone/Zone.h"

class DespawnCreatureTask : public Task {
	ManagedReference<AiAgent*> agent;

public:
	DespawnCreatureTask(AiAgent* creature);

	void run();
};
