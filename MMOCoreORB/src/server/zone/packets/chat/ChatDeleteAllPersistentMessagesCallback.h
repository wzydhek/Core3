#pragma once

#include "server/zone/packets/MessageCallback.h"

namespace server {
namespace zone {
namespace packets {
namespace chat {

class ChatDeleteAllPersistentMessagesCallback : public MessageCallback {
	uint64 playerID;
	uint64 targetID;

public:
	ChatDeleteAllPersistentMessagesCallback(ZoneClientSession* client, ZoneProcessServer* server);

	void parse(Message* message);

	void run();

};

} // namespace chat
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::chat;
