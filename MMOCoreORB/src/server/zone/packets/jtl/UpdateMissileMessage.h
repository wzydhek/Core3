#pragma once

#include "engine/service/proto/BaseMessage.h"
#include "server/zone/objects/ship/ShipObject.h"
#include "server/zone/managers/spacecombat/projectile/ShipProjectile.h"

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
