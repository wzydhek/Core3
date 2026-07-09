/*
 * GiveMoneyMessageCallback.h
 *
 *  Created on: 07/06/2010
 *      Author: victor
 */

#pragma once

#include "server/zone/packets/MessageCallback.h"

class GiveMoneyMessageCallback : public MessageCallback {
	uint32 money;

public:
	GiveMoneyMessageCallback(ZoneClientSession* client, ZoneProcessServer* server);

	void parse(Message* message);

	void run();

};
