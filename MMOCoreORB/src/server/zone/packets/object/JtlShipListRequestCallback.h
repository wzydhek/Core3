/*
 * JtlShipListRequestCallback.h
 *
 *  Created on: 04/25/2011
 *      Author: crush
 */

#pragma once

#include "ObjectControllerMessageCallback.h"

namespace server {
namespace zone {
namespace packets {
namespace object {

class JtlShipListRequestCallback : public MessageCallback {
	ObjectControllerMessageCallback* objectControllerMain;

	uint64 terminalObjectID;

public:
	JtlShipListRequestCallback(ObjectControllerMessageCallback* objectControllerCallback);

	void parse(Message* message);

	void run();
};

} // namespace object
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::object;
