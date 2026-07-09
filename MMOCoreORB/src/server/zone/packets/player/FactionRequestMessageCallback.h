/*
 * FactionRequestMessageCallback.h
 *
 *  Created on: Mar 18, 2011
 *      Author: crush
 */

#pragma once

#include "server/zone/packets/MessageCallback.h"

class FactionRequestMessageCallback : public MessageCallback {
public:
	FactionRequestMessageCallback(ZoneClientSession* client, ZoneProcessServer* server);

	void parse(Message* message);

	void run();
};
