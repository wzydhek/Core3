/*
 * ChatDeletePersistentMessageCallback.h
 *
 *  Created on: 13/03/2010
 *      Author: victor
 */

#pragma once

#include "server/zone/packets/MessageCallback.h"

namespace server {
namespace zone {
namespace packets {
namespace chat {

class ChatDeletePersistentMessageCallback : public MessageCallback {
	uint32 mailid;

public:
	ChatDeletePersistentMessageCallback(ZoneClientSession* client, ZoneProcessServer* server);

	void parse(Message* message);

	void run();

};

} // namespace chat
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::chat;
