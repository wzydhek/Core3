/*
 * InterplanetrySurveyTask.h
 *
 *  Created on: 6/8/2014
 *      Author: washu
 */

#pragma once

#include "server/ServerCore.h"
#include "server/zone/managers/resource/ResourceManager.h"
#include "server/chat/ChatManager.h"
#include "server/zone/managers/stringid/StringIdManager.h"
#include "server/zone/managers/resource/InterplanetarySurvey.h"

namespace server {
namespace zone {
namespace managers {
namespace resource {

class InterplanetarySurveyTask : public Task {
	ManagedReference<InterplanetarySurvey*> surveyData;

public:

	InterplanetarySurveyTask(InterplanetarySurvey* survey);

	void run();

};

} // namespace resource
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::resource;
