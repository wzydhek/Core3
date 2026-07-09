/*
 * GuildRequestCallback.h
 *
 *  Created on: Oct 29, 2010
 *      Author: crush
 */

#pragma once

#include "server/zone/packets/MessageCallback.h"

class GuildRequestCallback : public MessageCallback {
	uint64 objectID;

public:
	GuildRequestCallback(ZoneClientSession* client, ZoneProcessServer* server);

	void parse(Message* message);

	void run();
};
