/*
 * CancelLiveAuctionMessageCallback.h
 *
 *  Created on: Mar 17, 2011
 *      Author: polonel
 */

#pragma once

#include "server/zone/packets/MessageCallback.h"

namespace server {
namespace zone {
namespace packets {
namespace auction {

class CancelLiveAuctionMessageCallback : public MessageCallback {
	uint64 objectid;

public:
	CancelLiveAuctionMessageCallback(ZoneClientSession* client, ZoneProcessServer* server);

	void parse(Message* message);

	void run();

};

} // namespace auction
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::auction;
