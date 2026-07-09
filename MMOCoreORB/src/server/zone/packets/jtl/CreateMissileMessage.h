/*
 * CreateMissileMessage.h
 *
 *  Created on: Nov 20, 2008
 *      Author: swgemu
 */

#pragma once

#include "engine/service/proto/BaseMessage.h"
#include "server/zone/objects/scene/SceneObject.h"
#include "server/zone/objects/ship/ShipObject.h"
#include "server/zone/managers/spacecombat/projectile/ShipMissile.h"

class CreateMissileMessage : public BaseMessage {
	enum PlayerMissileType : int {
		CONCUSSION_MK1 = 0,
		CONCUSSION_MK2 = 1,
		CONCUSSION_MK3 = 2,
		IMAGEREC_MK1 = 3,
		IMAGEREC_MK2 = 4,
		PROTON_MK1 = 5,
		PROTON_MK2 = 6,
		PROTON_MK3 = 7,
		PROTON_MK4 = 8,
		SEISMIC_MK1 = 9,
		SEISMIC_MK2 = 10,
		SEISMIC_MK3 = 11,
		SPACEBOMB_MK1 = 12,
		SPACEBOMB_MK2 = 13
	};

	enum AiMissileType : int {
		AI_PROTON_TIER1 = 16,
		AI_PROTON_TIER2 = 17,
		AI_PROTON_TIER3 = 18,
		AI_PROTON_TIER4 = 19,
		AI_PROTON_TIER5 = 20
	};

public:
	CreateMissileMessage(SceneObject* source, SceneObject* target, int impactTime, int missileId, int missileType, int weaponSlot, int targetSlot);

	CreateMissileMessage(SceneObject* source, SceneObject* target, const Vector3& targetPosition, int impactTime, int missileId, int missileType, int weaponSlot, int targetSlot);

	CreateMissileMessage(ShipObject* source, ShipObject* target, const ShipMissile* missile);
};
