/*
 * CmdSceneReadyCallback.h
 *
 *  Created on: Sep 6, 2009
 *      Author: theanswer
 */

#pragma once

#include "server/zone/packets/MessageCallback.h"

namespace server {
namespace zone {
namespace packets {
namespace zone {

class CmdSceneReadyCallback : public MessageCallback {
public:
	CmdSceneReadyCallback(ZoneClientSession* client, ZoneProcessServer* server);

	void parse(Message* message);

	void run();
};

} // namespace zone
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::zone;
