/*
 * ObjectMenuSelect.h
 *
 *  Created on: 12/08/2009
 *      Author: victor
 */

#pragma once

#include "server/zone/packets/MessageCallback.h"

namespace server {
namespace zone {
namespace packets {
namespace object {

class ObjectMenuSelectCallback : public MessageCallback {
	uint64 objectID;
	uint8 radialID;
public:
	ObjectMenuSelectCallback(ZoneClientSession* client, ZoneProcessServer* server);

	void parse(Message* message);

	void run();
};

} // namespace object
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::object;
