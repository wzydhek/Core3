/*
 * RetrieveAuctionItemMessageCallback.h
 *
 *  Created on: 14/03/2010
 *      Author: victor
 */

#pragma once

#include "server/zone/packets/MessageCallback.h"

class RetrieveAuctionItemMessageCallback : public MessageCallback {
	uint64 objectid;
	uint64 bazaarid;

public:
	RetrieveAuctionItemMessageCallback(ZoneClientSession* client, ZoneProcessServer* server);

	void parse(Message* message);

	void run();

};
