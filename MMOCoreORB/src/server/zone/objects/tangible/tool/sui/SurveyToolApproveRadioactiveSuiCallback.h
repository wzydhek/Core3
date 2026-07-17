/*
 * SurveyToolApproveRadioactiveSuiCallback.h
 *
 *  Created on: may 22, 2012
 *      Author: kyle
 */

#pragma once

#include "server/zone/objects/tangible/tool/SurveyTool.h"
#include "server/zone/objects/player/sui/SuiCallback.h"

namespace server {
namespace zone {
namespace objects {
namespace tangible {
namespace tool {
namespace sui {

class SurveyToolApproveRadioactiveSuiCallback : public SuiCallback {
public:
	SurveyToolApproveRadioactiveSuiCallback(ZoneServer* server);

	void run(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args);
};

} // namespace sui
} // namespace tool
} // namespace tangible
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::tangible::tool::sui;
