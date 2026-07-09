/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "ScreenHandler.h"
#include "server/zone/objects/mission/MissionObject.h"
#include "engine/log/Logger.h"

namespace server {
namespace zone {
namespace objects {
namespace creature {
namespace conversation {
namespace screenhandlers {

class InformantMissionScreenHandler : public ScreenHandler, Logger {
protected:
	MissionObject* getBountyMissionObject(CreatureObject* player);

public:
	static const String STARTSCREENHANDLERID;

	InformantMissionScreenHandler() : ScreenHandler(), Logger("InformantMissionScreenHandler") {}

	ConversationScreen* handleScreen(CreatureObject* conversingPlayer, SceneObject* conversingNPC, int selectedOption, ConversationScreen* conversationScreen);

	bool toBinaryStream(ObjectOutputStream* stream);

	bool parseFromBinaryStream(ObjectInputStream* stream);
};

} // namespace screenhandlers
} // namespace conversation
} // namespace creature
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::creature::conversation::screenhandlers;
