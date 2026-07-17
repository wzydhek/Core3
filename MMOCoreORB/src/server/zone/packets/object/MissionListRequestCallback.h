/*
 * MissionListRequestCallback.h
 *
 *  Created on: 30/01/2010
 *      Author: victor
 */

#pragma once

#include "ObjectControllerMessageCallback.h"

namespace server {
namespace zone {
namespace packets {
namespace object {

class MissionListRequestCallback : public MessageCallback {
	uint16 flags;
	uint16 seq;
	uint64 terminalObjectID;

	ObjectControllerMessageCallback* objectControllerMain;

public:
	MissionListRequestCallback(ObjectControllerMessageCallback* objectControllerCallback);

	void parse(Message* message);

	void run();

};

} // namespace object
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::object;
