/*
 * PlayerMoneyRequest.h
 *
 *  Created on: 02/02/2010
 *      Author: victor
 */

#pragma once

#include "server/zone/packets/MessageCallback.h"

namespace server {
namespace zone {
namespace packets {
namespace player {

class PlayerMoneyRequestMessageCallback : public MessageCallback {
public:
	PlayerMoneyRequestMessageCallback(ZoneClientSession* client, ZoneProcessServer* server);

	void parse(Message* message);

	void run();

};

} // namespace player
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::player;
