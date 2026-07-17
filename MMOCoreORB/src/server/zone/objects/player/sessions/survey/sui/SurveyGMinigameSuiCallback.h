/*
 * SurveyGMinigameSuiCallback.h
 *
 *  Created on: may 22, 2012
 *      Author: kyle
 */

#pragma once

#include "server/zone/objects/player/sui/SuiCallback.h"
#include "server/zone/objects/player/sessions/survey/SurveySession.h"

namespace server {
namespace zone {
namespace objects {
namespace player {
namespace sessions {
namespace survey {
namespace sui {

class SurveyGMinigameSuiCallback : public SuiCallback {
public:
	SurveyGMinigameSuiCallback(ZoneServer* server);

	void run(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args);
};

} // namespace sui
} // namespace survey
} // namespace sessions
} // namespace player
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::player::sessions::survey::sui;
