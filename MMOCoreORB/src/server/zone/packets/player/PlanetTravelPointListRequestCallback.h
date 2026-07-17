/*
 * PlanetTravelPointListRequestCallback.h
 *
 *  Created on: 31/05/2010
 *      Author: victor
 */

#pragma once

#include "server/zone/packets/MessageCallback.h"

namespace server {
namespace zone {
namespace packets {
namespace player {

class PlanetTravelPointListRequestCallback : public MessageCallback {
	String zoneName;

public:
	PlanetTravelPointListRequestCallback(ZoneClientSession* client, ZoneProcessServer* server);

	void parse(Message* message);

	void run();
};

} // namespace player
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::player;
