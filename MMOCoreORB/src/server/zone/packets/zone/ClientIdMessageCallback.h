/*
 * ClientIdMessageCallback.h
 *
 *  Created on: Sep 4, 2009
 *      Author: theanswer
 */

#pragma once

#include "server/zone/packets/MessageCallback.h"

namespace server {
namespace zone {
namespace packets {
namespace zone {

class ClientIdMessageCallback : public MessageCallback {
	uint32 gameBits{};
	uint32 dataLen;
	String sessionID;
	uint32 accountID;
	String version;

public:
	ClientIdMessageCallback(ZoneClientSession* client, ZoneProcessServer* server);

	void parse(Message* message);

	void run();

	static void approveSession(ZoneClientSession* client, ZoneProcessServer* server, String sessionID, uint32 accountID);

	uint32 getDataLen() const;

	const String& getSessionID() const;

	uint32 getAccountID() const;
};

} // namespace zone
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::zone;
