/*
 * AddItemMessageCallback.h
 *
 *  Created on: 07/06/2010
 *      Author: victor
 */

#pragma once

#include "server/zone/packets/MessageCallback.h"

class AddItemMessageCallback : public MessageCallback {
	uint64 id;

public:
	AddItemMessageCallback(ZoneClientSession* client, ZoneProcessServer* server);

	void parse(Message* message);

	void run();
};
