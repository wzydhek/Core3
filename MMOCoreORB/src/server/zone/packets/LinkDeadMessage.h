/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "engine/service/proto/BaseMessage.h"

namespace server {
namespace zone {
namespace packets {

class LinkDeadMessage : public BaseMessage {
public:
	LinkDeadMessage();

};

} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets;
