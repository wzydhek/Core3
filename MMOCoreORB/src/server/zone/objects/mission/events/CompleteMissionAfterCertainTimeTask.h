/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "server/zone/objects/mission/MissionObjective.h"

namespace server {
namespace zone {
namespace objects {
namespace mission {
namespace events {

class CompleteMissionAfterCertainTimeTask : public Task {
	ManagedReference<MissionObjective*> objective;

public:
	CompleteMissionAfterCertainTimeTask(MissionObjective* objective);

	void run();
};

} // namespace events
} // namespace mission
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::mission::events;
