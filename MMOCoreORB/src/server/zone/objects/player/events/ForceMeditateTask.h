/*
 				Copyright <SWGEmu>
		See file COPYING for copying conditions. */


#pragma once

#include "engine/engine.h"
#include "server/zone/objects/creature/CreatureObject.h"

namespace server {
namespace zone {
namespace objects {
namespace player {
namespace events {

class ForceMeditateTask: public Task {
	ManagedReference<CreatureObject*> player;
	String moodString;

public:
	ForceMeditateTask(CreatureObject* pl);

	void setMoodString(const String& ms);

	String getMoodString();

	void run();

};

} // namespace events
} // namespace player
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::player::events;
