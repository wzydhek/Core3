/*
 * StomachRequestMessage.h
 *
 *  Created on: 02/02/2010
 *      Author: victor
 */

#pragma once

#include "server/zone/packets/MessageCallback.h"

class StomachRequestMessageCallback : public MessageCallback {
public:
	StomachRequestMessageCallback(ZoneClientSession* client, ZoneProcessServer* server);

	void parse(Message* message);

	void run();

};
