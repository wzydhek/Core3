/*
 * ClientInactivityMessage.h
 *
 *  Created on: 15/08/2009
 *      Author: victor
 */

#pragma once

#include "server/zone/packets/MessageCallback.h"

class ClientInactivityMessageCallback : public MessageCallback {
	byte flag;

public:
	ClientInactivityMessageCallback(ZoneClientSession* client, ZoneProcessServer* server);

	void parse(Message* message);

	void run();
};
