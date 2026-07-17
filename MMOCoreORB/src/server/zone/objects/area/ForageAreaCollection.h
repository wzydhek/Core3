/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "ForageArea.h"
#include "server/zone/managers/minigames/events/ForageCleanupEvent.h"
#include "server/zone/objects/creature/CreatureObject.h"

namespace server {
namespace zone {
namespace objects {
namespace area {

class ForageAreaCollection : public Object {

protected:

	Vector<Reference<ForageArea*> > forageAreas;
	Reference<Task*> cleanupEvent;


public:
	ForageAreaCollection(CreatureObject* player, short forageX, short forageY, const String& planet, int forageAreaType);


	bool checkForageAreas(short forageX, short forageY, const String& planet, int forageAreaType);

};

} // namespace area
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::area;
