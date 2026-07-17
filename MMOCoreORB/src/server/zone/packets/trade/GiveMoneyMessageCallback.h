/*
 * GiveMoneyMessageCallback.h
 *
 *  Created on: 07/06/2010
 *      Author: victor
 */

#pragma once

#include "server/zone/packets/MessageCallback.h"

namespace server {
namespace zone {
namespace packets {
namespace trade {

class GiveMoneyMessageCallback : public MessageCallback {
	uint32 money;

public:
	GiveMoneyMessageCallback(ZoneClientSession* client, ZoneProcessServer* server);

	void parse(Message* message);

	void run();

};

} // namespace trade
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::trade;
