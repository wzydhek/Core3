/*
 * CancelLiveAuctionMessageCallback.h
 *
 *  Created on: Mar 17, 2011
 *      Author: polonel
 */

#pragma once

#include "server/zone/packets/MessageCallback.h"

class CancelLiveAuctionMessageCallback : public MessageCallback {
	uint64 objectid;

public:
	CancelLiveAuctionMessageCallback(ZoneClientSession* client, ZoneProcessServer* server);

	void parse(Message* message);

	void run();

};
