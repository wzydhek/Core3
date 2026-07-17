/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

/**
 * \file SurveyTask.h
 * \author Kyle Burkhardt
 * \date 5-03-10
 */

#pragma once

#include "server/zone/packets/resource/SurveyMessage.h"
#include "server/zone/objects/player/PlayerObject.h"
#include "server/zone/objects/resource/ResourceSpawn.h"

namespace server {
namespace zone {
namespace managers {
namespace resource {
namespace resourcespawner {

class SurveyTask : public Task {
	ManagedReference<CreatureObject* > playerCreature;
	SurveyMessage* surveyMessage;
	ManagedReference<WaypointObject*> waypoint;
	float density;
	ManagedReference<ResourceSpawn*> resourceSpawn;

public:
	SurveyTask(ManagedReference<CreatureObject*> play, SurveyMessage* surveyM, ManagedReference<WaypointObject*> way, float density, ManagedReference<ResourceSpawn*> resourceSpawn);

	void run();
};

} // namespace resourcespawner
} // namespace resource
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::resource::resourcespawner;
