/*
 * DespawnShipAgentTask.h
 *
 * Created on: 2024-10-25
 * Author: Hakry
 */

#pragma once

#include "server/zone/objects/ship/ai/ShipAiAgent.h"
#include "server/zone/Zone.h"

class DespawnShipAgentTask : public Task {
	ManagedReference<ShipAiAgent*> shipAgent;

public:
	DespawnShipAgentTask(ShipAiAgent* agent);

	void run();

	void schedule(uint64 delay = 0);
};
