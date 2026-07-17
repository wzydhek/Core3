/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "ObjectControllerMessage.h"
#include "server/zone/objects/creature/CreatureObject.h"
#include "server/chat/StringIdChatParameter.h"

//TODO: This needs more research!

namespace server {
namespace zone {
namespace packets {
namespace object {

class NpcConversationMessage : public ObjectControllerMessage {
public:

	NpcConversationMessage(CreatureObject* creo, const UnicodeString& message);

	NpcConversationMessage(CreatureObject* creo, StringIdChatParameter& stringid);
};

} // namespace object
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::object;
