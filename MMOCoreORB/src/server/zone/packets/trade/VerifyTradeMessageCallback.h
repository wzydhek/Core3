/*
 * VerifyTradeMessageCallback.h
 *
 *  Created on: 07/06/2010
 *      Author: victor
 */

#pragma once

#include "server/zone/packets/MessageCallback.h"

class VerifyTradeMessageCallback : public MessageCallback {


public:
	VerifyTradeMessageCallback(ZoneClientSession* client, ZoneProcessServer* server);

	void parse(Message* message);

	void run();

};
