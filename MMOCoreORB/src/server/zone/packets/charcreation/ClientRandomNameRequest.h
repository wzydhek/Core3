/*
 * ClientRandomNameRequest.h
 *
 *  Created on: 22/07/2009
 *      Author: TheAnswer
 */

#pragma once

#include "server/zone/packets/MessageCallback.h"

namespace server {
namespace zone {
namespace packets {
namespace charcreation {

class ClientRandomNameRequest : public MessageCallback {
	String raceFile;

public:
	ClientRandomNameRequest(ZoneClientSession* client, ZoneProcessServer* server);

	void parse(Message* message);

	void run();
};

} // namespace charcreation
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::charcreation;
