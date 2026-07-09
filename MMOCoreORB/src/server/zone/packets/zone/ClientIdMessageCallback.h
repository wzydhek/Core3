/*
 * ClientIdMessageCallback.h
 *
 *  Created on: Sep 4, 2009
 *      Author: theanswer
 */

#pragma once

#include "server/zone/packets/MessageCallback.h"


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
