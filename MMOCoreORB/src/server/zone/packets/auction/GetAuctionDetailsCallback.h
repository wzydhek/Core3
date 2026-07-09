/*
 * GetAuctionDetailsCallback.h
 *
 *  Created on: 13/03/2010
 *      Author: victor
 */

#pragma once

#include "server/zone/packets/MessageCallback.h"

class GetAuctionDetailsCallback : public MessageCallback {
	uint64 objectid;

public:
	GetAuctionDetailsCallback(ZoneClientSession* client, ZoneProcessServer* server);

	void parse(Message* message);

	void run();

};
