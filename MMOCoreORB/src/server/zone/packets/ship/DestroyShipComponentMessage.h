#pragma once

#include "engine/service/proto/BaseMessage.h"
#include "server/zone/objects/ship/ShipObject.h"

namespace server {
namespace zone {
namespace packets {
namespace ship {

class DestroyShipComponentMessage : public BaseMessage {
public:
	DestroyShipComponentMessage(ShipObject* ship, int slot, float scale);
};

} // namespace ship
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::ship;
