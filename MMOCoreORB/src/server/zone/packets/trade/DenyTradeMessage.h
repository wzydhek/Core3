/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "engine/service/proto/BaseMessage.h"
#include "server/zone/packets/MessageCallback.h"

namespace server {
namespace zone {
namespace packets {
namespace trade {

class DenyTradeMessage : public BaseMessage {
public:
	DenyTradeMessage();
};

class DenyTradeMessageCallback : public MessageCallback {
public:
	DenyTradeMessageCallback(ZoneClientSession *session, ZoneProcessServer *server);

	void parse(Message *message);

	void run();
};

} // namespace trade
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::trade;
