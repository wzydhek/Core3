/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "engine/engine.h"
#include "server/zone/Zone.h"
#include "server/zone/objects/area/SarlaccArea.h"
#include "server/zone/objects/creature/CreatureObject.h"
#include "templates/params/creature/CreatureAttribute.h"

namespace server {
namespace zone {
namespace objects {
namespace area {
namespace events {

class SarlaccEruptTask: public Task {
	ManagedReference<SarlaccArea*> sarlaccArea;


public:
	SarlaccEruptTask(SarlaccArea* area);

	void run();
};

} // namespace events
} // namespace area
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::area::events;
