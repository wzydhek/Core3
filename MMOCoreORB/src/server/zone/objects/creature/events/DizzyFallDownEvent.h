/*
 * DizzyFallDownEvent.h
 *
 *  Created on: 02/06/2010
 *      Author: victor
 */

#pragma once

#include "server/zone/objects/creature/CreatureObject.h"

namespace server {
namespace zone {
namespace objects {
namespace creature {
namespace events {

class DizzyFallDownEvent : public Task {
	ManagedReference<CreatureObject*> creature;
public:

	DizzyFallDownEvent(CreatureObject* creat);

	void run();
};

}
}
}
}
}

using namespace server::zone::objects::creature::events;
