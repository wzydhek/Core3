/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "engine/service/proto/BaseMessage.h"

namespace server {
namespace zone {
namespace packets {
namespace trade {

class BeginTradeMessage : public BaseMessage {
public:
	BeginTradeMessage(uint64 playerID);
};

} // namespace trade
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::trade;
