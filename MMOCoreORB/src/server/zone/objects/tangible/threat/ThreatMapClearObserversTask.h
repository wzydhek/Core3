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

namespace server {
namespace zone {
namespace objects {
namespace tangible {
namespace threat {

class ThreatMapClearObserversTask : public Task {
	ThreatMap threatMap;
	ManagedReference<ThreatMapObserver*> threatMapObserver;

public:
	ThreatMapClearObserversTask(const ThreatMap& map, ThreatMapObserver* obs);

	void run();
};

} // namespace threat
} // namespace tangible
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::tangible::threat;
