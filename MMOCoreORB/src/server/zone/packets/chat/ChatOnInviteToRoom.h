/*
 * ChatOnInviteToRoom.h
 *
 *  Created on: Feb 12, 2016
 *      Author: Anakis
 */

#pragma once

#include "engine/service/proto/BaseMessage.h"
#include "server/zone/objects/creature/CreatureObject.h"

namespace server {
namespace zone {
namespace packets {
namespace chat {

class ChatOnInviteToRoom : public BaseMessage {
public:
	ChatOnInviteToRoom(CreatureObject* inviter, const String& invitee, const String& roomPath, int error, int requestID);

};

} // namespace chat
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::chat;
