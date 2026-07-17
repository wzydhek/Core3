#pragma once

#include "engine/service/proto/BaseMessage.h"
#include "server/zone/objects/ship/ShipObject.h"
#include "server/zone/managers/spacecombat/projectile/ShipProjectile.h"

namespace server {
namespace zone {
namespace packets {
namespace jtl {

class UpdateMissileMessage : public BaseMessage {
public:
	enum UpdateType : int {
		MISS = 0,
		HIT = 1,
		COUNTERED = 2,
		COUNTERFAILED = 3
	};

	UpdateMissileMessage(ShipObject* ship, const ShipProjectile* projectile, int countermeasureType, int updateType);
};

} // namespace jtl
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::jtl;
