/*
 * RequestGalaxyLoopTimes.h
 *
 *  Created on: 15/08/2009
 *      Author: victor
 */

#pragma once

#include "engine/service/proto/BaseMessage.h"
#include "server/zone/packets/MessageCallback.h"

namespace server {
namespace zone {
namespace packets {
namespace zone {

class GalaxyLoopTimesResponse : public BaseMessage {
public:
	GalaxyLoopTimesResponse();
};

class RequestGalaxyLoopTimesCallback : public MessageCallback {
public:
	RequestGalaxyLoopTimesCallback(ZoneClientSession* client, ZoneProcessServer* server);

	void parse(Message* message);

	void run();
};

} // namespace zone
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::zone;
