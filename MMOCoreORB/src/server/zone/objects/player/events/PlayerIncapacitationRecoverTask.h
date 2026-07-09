/*
 * PlayerIncapacitationRecoverTask.h
 *
 *  Created on: 30/05/2010
 *      Author: victor
 */

#pragma once

#include "templates/params/creature/CreatureAttribute.h"
#include "server/zone/objects/creature/CreatureObject.h"

namespace server {
namespace zone {
namespace objects {
namespace player {
namespace events {

class PlayerIncapacitationRecoverTask : public Task {
	ManagedReference<CreatureObject*> player;
	bool deadRecovery;

public:
	PlayerIncapacitationRecoverTask(CreatureObject* pl, bool deadRecovery);

	~PlayerIncapacitationRecoverTask();

	void run();

};

}
}
}
}
}

using namespace server::zone::objects::player::events;
