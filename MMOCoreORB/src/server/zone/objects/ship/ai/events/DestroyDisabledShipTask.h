/*
 * DestroyDisabledShipTask.h
 *
 * Created on: 2026-02-21
 * Author: Hakry
 */

#pragma once

#include "server/zone/objects/ship/ai/ShipAiAgent.h"
#include "server/zone/objects/ship/events/DestroyShipTask.h"
#include "server/zone/Zone.h"

class DestroyDisabledShipTask : public Task {
	ManagedWeakReference<ShipAiAgent*> shipAgent;

public:
	DestroyDisabledShipTask(ShipAiAgent* agent);

	void run();

	void schedule(uint64 delay = 0);
};
