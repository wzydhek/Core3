/*
 * CreateAuctionMessageCallback.h
 *
 *  Created on: 13/03/2010
 *      Author: victor
 */

#pragma once

#include "server/zone/packets/MessageCallback.h"

class CreateAuctionMessageCallback : public MessageCallback {
	uint64 objectID;
	uint64 vendorID;

	uint32 price;
	uint32 duration;

	UnicodeString description;

	byte premium;
public:
	CreateAuctionMessageCallback(ZoneClientSession* client, ZoneProcessServer* server);

	void parse(Message* message);

	void run();

};
