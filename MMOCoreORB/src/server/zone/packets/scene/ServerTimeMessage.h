/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "engine/service/proto/BaseMessage.h"
#include "server/zone/Zone.h"

namespace server {
namespace zone {
namespace packets {
namespace scene {

class ServerTimeMessage : public BaseMessage {
public:
	ServerTimeMessage(uint64 time);
	
	ServerTimeMessage(Zone* zone);
	
};

} // namespace scene
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::scene;
