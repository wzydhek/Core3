/*
 * EntertainingSessionTask.h
 *
 *  Created on: 27/09/2010
 *      Author: victor
 */

#pragma once

#include "engine/engine.h"
#include "server/zone/objects/player/sessions/EntertainingSession.h"

namespace server {
namespace zone {
namespace objects {
namespace player {
namespace events {


class EntertainingSessionTask : public Task {
	ManagedWeakReference<EntertainingSession*> session;
public:
	EntertainingSessionTask(EntertainingSession* sess);

	void run();
};


}
}
}
}
}

using namespace server::zone::objects::player::events;
