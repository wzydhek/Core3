
#pragma once

#include "server/zone/objects/scene/SceneObject.h"
#include "server/zone/objects/player/sui/SuiCallback.h"
#include "server/zone/managers/objectcontroller/ObjectController.h"

namespace server {
namespace zone {
namespace objects {
namespace player {
namespace sui {
namespace callbacks {

class FindObjectSuiCallback : public SuiCallback {

public:
	FindObjectSuiCallback(ZoneServer* serv);

	void run(CreatureObject* creature, SuiBox* sui, uint32 eventIndex, Vector<UnicodeString>* args);
};

} // namespace callbacks
} // namespace sui
} // namespace player
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::player::sui::callbacks;
