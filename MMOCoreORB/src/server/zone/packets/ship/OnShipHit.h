//
// Created by vagrant on 8/23/17.
//

#pragma once

#include "server/zone/packets/object/ObjectControllerMessage.h"
#include "server/zone/objects/ship/ShipObject.h"

namespace server {
namespace zone {
namespace packets {
namespace ship {

class OnShipHit : public ObjectControllerMessage {
public:
	OnShipHit(ShipObject* ship, const Vector3& hitDirection, int shipHitType, float newPercent, float oldPercent);
};

} // namespace ship
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::ship;
