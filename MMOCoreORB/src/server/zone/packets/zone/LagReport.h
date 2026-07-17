/*
 * LagReport.h
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

class GameServerLagResponse : public BaseMessage {
public:
	GameServerLagResponse();
};

class ConnectionServerLagResponse : public BaseMessage {
public:
	ConnectionServerLagResponse();
};

class LagReportCallback : public MessageCallback {
	uint32 connectionServerLag;
	uint32 gameServerLag;
public:
	LagReportCallback(ZoneClientSession* client, ZoneProcessServer* server);

	void parse(Message* message);

	void run();
};

class LagRequestCallback : public MessageCallback {
public:
	LagRequestCallback(ZoneClientSession* client, ZoneProcessServer* server);

	void parse(Message* message);

	void run();
};

} // namespace zone
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::zone;
