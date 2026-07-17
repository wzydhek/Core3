/*
 * PlayerTeachConfirmSuiCallback.h
 *
 *  Created on: Mar 13, 2012
 *      Author: katherine
 */

#pragma once

#include "server/zone/objects/player/sui/SuiCallback.h"
#include "server/zone/objects/creature/variables/Skill.h"

namespace server {
namespace zone {
namespace objects {
namespace player {
namespace sui {
namespace callbacks {

class PlayerTeachConfirmSuiCallback: public SuiCallback {
	WeakReference<Skill*> skill;

public:
	PlayerTeachConfirmSuiCallback(ZoneServer* serv, Skill* skl);

	void run(CreatureObject* student, SuiBox* sui, uint32 eventIndex, Vector<UnicodeString>* args);
};

} // namespace callbacks
} // namespace sui
} // namespace player
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::player::sui::callbacks;
