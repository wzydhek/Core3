/*
 * MissionAcceptCallback.h
 *
 *  Created on: 22/06/2010
 *      Author: victor
 */

#pragma once

#include "ObjectControllerMessageCallback.h"

namespace server {
namespace zone {
namespace packets {
namespace object {

class MissionAcceptCallback : public MessageCallback {
	uint64 missionObjectID;
	uint64 terminalObjectID;
	uint8 terminalIndex;

	ObjectControllerMessageCallback* objectControllerMain;
public:
	MissionAcceptCallback(ObjectControllerMessageCallback* objectControllerCallback);

	void parse(Message* message);

	void run();
};

} // namespace object
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::object;
