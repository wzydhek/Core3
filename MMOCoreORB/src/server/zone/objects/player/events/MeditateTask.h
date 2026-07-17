/*
 				Copyright <SWGEmu>
		See file COPYING for copying conditions. */

/**
 * \file MeditateTask.h
 * \author Polonel
 * \date 08.04.2010
 */

#pragma once

#include "engine/engine.h"
#include "server/chat/StringIdChatParameter.h"
#include "server/zone/objects/creature/CreatureObject.h"
#include "templates/params/creature/CreatureAttribute.h"

namespace server {
namespace zone {
namespace objects {
namespace player {
namespace events {

class MeditateTask: public Task {
	ManagedReference<CreatureObject*> player;
	String moodString;

public:
	MeditateTask(CreatureObject* pl);

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
