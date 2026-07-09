/*
 * ThreatMapClearObserversTask.h
 *
 *  Created on: 08/04/2012
 *      Author: victor
 */

#pragma once

#include "engine/engine.h"
#include "server/zone/objects/tangible/threat/ThreatMap.h"
#include "server/zone/objects/tangible/threat/ThreatMapObserver.h"

class ThreatMapClearObserversTask : public Task {
	ThreatMap threatMap;
	ManagedReference<ThreatMapObserver*> threatMapObserver;

public:
	ThreatMapClearObserversTask(const ThreatMap& map, ThreatMapObserver* obs);

	void run();
};
