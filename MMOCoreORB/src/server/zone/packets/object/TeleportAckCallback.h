/*
 * TeleportAckCallback.h
 *
 *  Created on: 27/11/2010
 *      Author: victor
 */

#pragma once

#include "../MessageCallback.h"
#include "ObjectControllerMessageCallback.h"

namespace server {
namespace zone {
namespace packets {
namespace object {

class TeleportAckCallback : public MessageCallback {
	uint32 movementCounter;
	ObjectControllerMessageCallback* objectControllerMain;

public:
	TeleportAckCallback(ObjectControllerMessageCallback* objectControllerCallback);

	void parse(Message* message);

	void run();
};

} // namespace object
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::object;
