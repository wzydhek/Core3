/*
 * FactionRequestMessageCallback.h
 *
 *  Created on: Mar 18, 2011
 *      Author: crush
 */

#pragma once

#include "server/zone/packets/MessageCallback.h"

namespace server {
namespace zone {
namespace packets {
namespace player {

class FactionRequestMessageCallback : public MessageCallback {
public:
	FactionRequestMessageCallback(ZoneClientSession* client, ZoneProcessServer* server);

	void parse(Message* message);

	void run();
};

} // namespace player
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::player;
