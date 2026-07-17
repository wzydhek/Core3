/*
 * CreateImmediateAuctionMessageCallback.h
 *
 *  Created on: 13/03/2010
 *      Author: victor
 */

#pragma once

#include "server/zone/packets/MessageCallback.h"

namespace server {
namespace zone {
namespace packets {
namespace auction {

class CreateImmediateAuctionMessageCallback : public MessageCallback {
	uint64 objectID;
	uint64 vendorID;

	uint32 price;
	uint32 duration;
	byte premium;

	UnicodeString description;
public:
	CreateImmediateAuctionMessageCallback(ZoneClientSession* client, ZoneProcessServer* server);

	void parse(Message* message);

	void run();

};

} // namespace auction
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::auction;
