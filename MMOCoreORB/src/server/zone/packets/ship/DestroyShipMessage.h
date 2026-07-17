//
// Created by g on 1/1/18.
//

#pragma once

#include "engine/service/proto/BaseMessage.h"

namespace server {
namespace zone {
namespace packets {
namespace ship {

class DestroyShipMessage : public BaseMessage {
public:
	DestroyShipMessage(uint64 objectID, float scale);
};

} // namespace ship
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::ship;
