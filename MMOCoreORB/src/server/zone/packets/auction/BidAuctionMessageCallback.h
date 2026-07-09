/*
 * BidAuctionMessageCallback.h
 *
 *  Created on: 14/03/2010
 *      Author: victor
 */

#pragma once

#include "server/zone/packets/MessageCallback.h"

class BidAuctionMessageCallback : public MessageCallback {
	uint64 objectid;
	uint32 price1;
	uint32 price2;

public:
	BidAuctionMessageCallback(ZoneClientSession* client, ZoneProcessServer* server);

	void parse(Message* message);

	void run();

};
