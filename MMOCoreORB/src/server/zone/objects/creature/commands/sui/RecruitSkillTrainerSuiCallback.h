/*
 * RecruitSkillTrainer.h
 *
 *  Created on: Apr. 26 2012
 *      Author: TragD
 */

#pragma once

#include "server/zone/objects/player/sui/SuiCallback.h"

namespace server {
namespace zone {
namespace objects {
namespace creature {
namespace commands {
namespace sui {

class RecruitSkillTrainerSuiCallback : public SuiCallback {
public:
	RecruitSkillTrainerSuiCallback(ZoneServer* server);

	void run(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args);
};

} // namespace sui
} // namespace commands
} // namespace creature
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::creature::commands::sui;
