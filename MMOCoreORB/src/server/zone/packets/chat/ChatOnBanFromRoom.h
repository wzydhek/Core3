/*
 * ChatOnBanFromRoom.h
 *
 *  Created on: Feb 19, 2016
 *      Author: Anakis
 */

#pragma once

#include "engine/service/proto/BaseMessage.h"
#include "server/zone/objects/creature/CreatureObject.h"

namespace server {
namespace zone {
namespace packets {
namespace chat {

class ChatOnBanFromRoom : public BaseMessage {
public:
	ChatOnBanFromRoom(CreatureObject* banner, const String& baneeName, const String& roomPath, int error, int requestID = 0);

};

} // namespace chat
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::chat;
