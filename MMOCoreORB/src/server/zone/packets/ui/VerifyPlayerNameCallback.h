/*
 * VerifyPlayerNameCallback.h
 *
 *  Created on: Nov 22, 2010
 *      Author: crush
 */

#pragma once

#include "server/zone/packets/MessageCallback.h"

class VerifyPlayerNameCallback : public MessageCallback {
	UnicodeString name;
	uint64 playerID;

public:
	VerifyPlayerNameCallback(ZoneClientSession* client, ZoneProcessServer* server);


	void parse(Message* message);

	void run();
};
