/*
 * VerifyPlayerNameCallback.h
 *
 *  Created on: Nov 22, 2010
 *      Author: crush
 */

#pragma once

#include "server/zone/packets/MessageCallback.h"

namespace server {
namespace zone {
namespace packets {
namespace ui {

class VerifyPlayerNameCallback : public MessageCallback {
	UnicodeString name;
	uint64 playerID;

public:
	VerifyPlayerNameCallback(ZoneClientSession* client, ZoneProcessServer* server);


	void parse(Message* message);

	void run();
};

} // namespace ui
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::ui;
