/*
 * ConnectPlayerResponseMessage.h
 *
 *  Created on: Nov 25, 2008
 *      Author: swgemu
 */

#pragma once

#include "engine/service/proto/BaseMessage.h"
#include "server/zone/packets/MessageCallback.h"

class ConnectPlayerResponseMessage : public BaseMessage {
public:
	ConnectPlayerResponseMessage();

};

class ConnectPlayerMessageCallback : public MessageCallback {
public:
	ConnectPlayerMessageCallback(ZoneClientSession* client, ZoneProcessServer* server);

	void parse(Message* message);

	void run();
};
