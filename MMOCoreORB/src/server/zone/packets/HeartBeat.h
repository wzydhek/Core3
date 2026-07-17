/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "engine/service/proto/BaseMessage.h"

//Even though this opcode isnt in our tables, its required for some reason to make things work :(

namespace server {
namespace zone {
namespace packets {

class HeartBeat : public BaseMessage {
public:
	HeartBeat();

};

} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets;
