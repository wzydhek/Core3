/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "server/zone/objects/creature/ai/DroidObject.h"
#include "server/zone/objects/tangible/components/droid/DroidPlaybackModuleDataComponent.h"

namespace server {
namespace zone {
namespace objects {
namespace creature {
namespace events {

class DroidPlaybackEvent : public Task {

	Reference<DroidPlaybackModuleDataComponent*> module;
	ManagedReference<CreatureObject*> player;
	int action;
	int performanceIndex;
public:
	const static uint8 SET_TRACK = 0;
	const static uint8 CHANGE_SONG = 1;
	const static uint8 STOP_PLAYING = 2;

	DroidPlaybackEvent(DroidPlaybackModuleDataComponent* module, CreatureObject* player, int perfIndex, int action);

	void run();
};

} // events
} // creature
} // objects
} // zone
} // server

using namespace server::zone::objects::creature::events;
