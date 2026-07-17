/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

/**
 * \file SampleTask.h
 * \author Kyle Burkhardt
 * \date 5-03-10
 */

#pragma once

#include "server/zone/objects/tangible/tool/SurveyTool.h"
#include "server/zone/objects/player/sessions/survey/SurveySession.h"
#include "server/zone/objects/creature/CreatureObject.h"

namespace server {
namespace zone {
namespace managers {
namespace resource {
namespace resourcespawner {

class SampleTask : public Task {

protected:
	ManagedReference<CreatureObject*> playerCreature;
	ManagedReference<SurveyTool* > surveyTool;
	bool cancelled;

public:
	SampleTask(CreatureObject* play, SurveyTool* tool);

	void run();


	void stopSampling();

	bool isCancelled();

};

} // namespace resourcespawner
} // namespace resource
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::resource::resourcespawner;
