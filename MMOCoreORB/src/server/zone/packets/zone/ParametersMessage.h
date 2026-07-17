/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "engine/service/proto/BaseMessage.h"
#include "server/zone/packets/MessageCallback.h"

namespace server {
namespace zone {
namespace packets {
namespace zone {

class ParametersMessage : public BaseMessage {
public:
	ParametersMessage();

	static void parse(Packet* pack);

};

class ParametersMessageCallback : public MessageCallback {
	uint16 ackSequence;
public:
	ParametersMessageCallback(ZoneClientSession* client, ZoneProcessServer* server);

	void parse(Message* msg);

	void execute();
};

} // namespace zone
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::zone;
