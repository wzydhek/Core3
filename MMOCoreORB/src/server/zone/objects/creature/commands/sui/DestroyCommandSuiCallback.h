/*
 * DestroyCommandSuiCallback.h
 *
 *  Created on: Nov 3, 2010
 *      Author: crush
 */

#pragma once

#include "server/zone/objects/player/sui/SuiCallback.h"

namespace server {
namespace zone {
namespace objects {
namespace creature {
namespace commands {
namespace sui {

class DestroyCommandSuiCallback : public SuiCallback {
public:
	DestroyCommandSuiCallback(ZoneServer* server);

	void run(CreatureObject* creature, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args);
};

} // namespace sui
} // namespace commands
} // namespace creature
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::creature::commands::sui;
