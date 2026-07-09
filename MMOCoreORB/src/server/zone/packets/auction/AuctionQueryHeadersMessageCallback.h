/*
 * AuctionQueryHeadersMessageCallback.h
 *
 *  Created on: 30/01/2010
 *      Author: victor
 */

#pragma once

#include "server/zone/packets/MessageCallback.h"

class AuctionQueryHeadersMessageCallback : public MessageCallback {
	int locationType;
	int counter;
	int searchType;
	uint32 itemCategory;
	int unk1;
	UnicodeString filterText;
	int unk2;
	int minPrice;
	int maxPrice;
	bool includeEntranceFee;
	uint64 vendorID;
	bool isVendor;
	int offset;

public:
	AuctionQueryHeadersMessageCallback(ZoneClientSession* client, ZoneProcessServer* server);

	void parse(Message* message);

	void run();
};
