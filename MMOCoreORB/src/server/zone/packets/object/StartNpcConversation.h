/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "ObjectControllerMessage.h"
#include "server/zone/objects/creature/CreatureObject.h"

namespace server {
namespace zone {
namespace packets {
namespace object {

class StartNpcConversation : public ObjectControllerMessage {
public:
	StartNpcConversation(CreatureObject* creo, uint64 npcID, byte starter, const String& ascii, uint32 crc = 0);
};

} // namespace object
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::object;
