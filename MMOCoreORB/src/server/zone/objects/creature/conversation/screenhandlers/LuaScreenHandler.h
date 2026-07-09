/*
 * LuaScreenHandler.h
 *
 *  Created on: 03/01/2012
 *      Author: victor
 */

#pragma once

#include "ScreenHandler.h"
#include "engine/log/Logger.h"
#include "system/io/ObjectInputStream.h"
#include "system/io/ObjectOutputStream.h"

namespace server {
namespace zone {
namespace objects {
namespace creature {
namespace conversation {
namespace screenhandlers {

class LuaScreenHandler : public ScreenHandler, Logger, public Object {
protected:

public:
	LuaScreenHandler();

	virtual ConversationScreen* handleScreen(CreatureObject* conversingPlayer, SceneObject* conversingNPC, int selectedOption, ConversationScreen* conversationScreen) = 0;

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
