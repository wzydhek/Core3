/*
 * ShipUpdateTransformCallback.h
 *
 *  Created on: 01/09/2011
 *      Author: TheAnswer
 */

#pragma once

// #define SHIP_TRANSFORM_DEBUG

#include "server/zone/packets/MessageCallback.h"
#include "server/zone/packets/ship/PackedVelocity.h"
#include "server/zone/packets/ship/PackedRotationRate.h"
#include "server/zone/objects/ship/ShipObject.h"
#include "server/zone/objects/creature/CreatureObject.h"


class ShipUpdateTransformCallback : public MessageCallback {
private:
	const static bool errorLog = false;

	const static int PRIORITY_MAX = 25;

#ifdef SHIP_TRANSFORM_DEBUG
	const static bool sendText = true;
	const static bool sendPath = true;
	const static bool drawPathRadius = false;
#endif // SHIP_TRANSFORM_DEBUG

protected:
	const static constexpr float positionMod = 1.5f;
	const static constexpr float positionScale = 8000.f / 32767.f;
	const static constexpr float directionScale = 1.f / 127.f;

	uint16 shipId;

	int8 dirX;
	int8 dirY;
	int8 dirZ;
	int8 dirW;

	int16 posX;
	int16 posZ;
	int16 posY;

	PackedVelocity velocity;
	PackedRotationRate yawRate;
	PackedRotationRate pitchRate;
	PackedRotationRate rollRate;

	uint32 counter;

	float positionX;
	float positionY;
	float positionZ;

	float directionX;
	float directionY;
	float directionZ;
	float directionW;

	long deltaTime;

public:
	ShipUpdateTransformCallback(ZoneClientSession* client, ZoneProcessServer* server);

	void parse(Message* message);

	void run();

	bool isPositionValid() const;

	bool isPositionUpdate(ShipObject* ship) const;

	bool isStaticUpdate(ShipObject* ship);

	void updateCollision(ShipObject* ship, CreatureObject* pilot, const Vector3& collisionPoint);

	void updatePosition(ShipObject* ship, CreatureObject* pilot);

	void updateStatic(ShipObject* ship, CreatureObject* pilot);

	void synchronize(ShipObject* ship, CreatureObject* pilot);

	void updateTransform(ShipObject* ship, const Vector3& position, bool reorthonormalize);

	void broadcastTransform(ShipObject* ship, const Vector3& position);

	void updateError(CreatureObject* pilot, const String& message, bool bounceBack);

#ifdef SHIP_TRANSFORM_DEBUG
	void sendDebug(CreatureObject* pilot, ShipObject* ship, const String& message, const Vector3& position);

	void sendDebugMessage(CreatureObject* pilot, ShipObject* ship, const String& message, const Vector3& position);

	void sendDebugPath(CreatureObject* pilot, ShipObject* ship, const Vector3& nextPosition);
#endif // SHIP_TRANSFORM_DEBUG
};
