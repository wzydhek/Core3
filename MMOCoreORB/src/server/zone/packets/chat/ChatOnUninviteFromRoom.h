/*
 * ChatOnUninviteFromRoom.h
 *
 *  Created on: Feb 14, 2016 - Yes, pretty sad huh? SWGEmu is my lady!! Lol!
 *      Author: Anakis
 */

#pragma once

#include "engine/service/proto/BaseMessage.h"
#include "server/zone/objects/creature/CreatureObject.h"

namespace server {
namespace zone {
namespace packets {
namespace chat {

class ChatOnUninviteFromRoom : public BaseMessage {
public:
	ChatOnUninviteFromRoom(CreatureObject* uninviter, const String& uninvitee, const String& roomPath, int error, int requestID);

};

} // namespace chat
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::chat;
