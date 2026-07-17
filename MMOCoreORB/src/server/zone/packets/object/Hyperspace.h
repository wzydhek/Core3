//
// Created by g on 12/20/17.
//

#pragma once

#include "engine/service/proto/BaseMessage.h"

namespace server {
namespace zone {
namespace packets {
namespace object {

class HyperspaceMessage : public BaseMessage {
public:
	HyperspaceMessage(uint64 shpid, int operand);
};

} // namespace object
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::object;
