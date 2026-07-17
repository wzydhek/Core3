/*
 * CreateProjecticeMessage.h
 *
 *  Created on: Nov 20, 2008
 *      Author: swgemu
 */

#pragma once

#include "engine/service/proto/BaseMessage.h"
#include "server/zone/packets/MessageCallback.h"
#include "engine/util/u3d/Vector3.h"
#include "server/zone/packets/ship/PackedPosition.h"
#include "server/zone/objects/creature/CreatureObject.h"
#include "server/zone/managers/spacecombat/projectile/ShipProjectile.h"
#include "server/zone/objects/ship/ShipProjectileData.h"

namespace server {
namespace zone {
namespace packets {
namespace jtl {

class CreateProjectileMessage : public BaseMessage {
private:
	constexpr static float directionScale = PackedPosition::positionScale * ShipProjectile::positionScale;

public:
	CreateProjectileMessage(Vector3 position, Vector3 direction, uint8 component, uint8 projectile, uint8 weapon, uint16 shipID, uint32 sequence);

	CreateProjectileMessage(ShipObject* ship, const ShipProjectile* projectile, uint32 syncStamp = 0);
};

class CreateProjectileMessageCallback : public MessageCallback {
protected:
	uint16 shipID;
	uint8 weaponIndex;
	uint8 projectileType;
	uint8 componentIndex;
	Vector3 position;
	Vector3 direction;
	uint32 sequence;

public:
	CreateProjectileMessageCallback(ZoneClientSession* client, ZoneProcessServer* server);

	void parse(Message* message);

	void run();

	void launchCountermeasure(ShipObject* ship, CreatureObject* pilot, const ShipProjectileData* data) const;

	void launchMissile(ShipObject* ship, CreatureObject* pilot, const ShipProjectileData* data) const;

	const char* getTaskName();
};

} // namespace jtl
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::jtl;
