/*
 * EmptyHopperCallback.h
 *
 *  Created on: 14/06/2010
 *      Author: victor
 */

#pragma once

#include "ObjectControllerMessageCallback.h"

namespace server {
namespace zone {
namespace packets {
namespace object {

class EmptyHopperCallback : public MessageCallback {
	uint64 harvesterId;
	uint64 resourceId;
	uint32 quantity;
	uint8 byte1;
	uint8 byte2;

	ObjectControllerMessageCallback* objectControllerMain;
public:
	EmptyHopperCallback(ObjectControllerMessageCallback* objectControllerCallback);

	void parse(Message* message);

	void run();
};

} // namespace object
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::object;
