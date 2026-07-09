/*
 * ShipUpdateTransformMessage.h
 *
 *  Created on: 01/09/2011
 *	  Author: TheAnswer
 */

#pragma once

#include "engine/service/proto/BaseMessage.h"
#include "server/zone/objects/ship/ShipObject.h"
#include "PackedVelocity.h"
#include "PackedRotationRate.h"

class ShipUpdateTransformMessage : public BaseMessage {
public:
	ShipUpdateTransformMessage(ShipObject* ship, uint32 syncStamp = 0);

	ShipUpdateTransformMessage(ShipObject* ship, PackedVelocity& velocity, PackedRotationRate& rA, PackedRotationRate& rB, PackedRotationRate& rC, uint32 syncStamp = 0);

	ShipUpdateTransformMessage(ShipObject* ship, const Vector3& position, PackedVelocity& velocity, PackedRotationRate& rA, PackedRotationRate& rB, PackedRotationRate& rC, uint32 syncStamp = 0);

	ShipUpdateTransformMessage(ShipObject* ship, const Quaternion* direction, const Vector3& position, PackedVelocity& velocity, PackedRotationRate& rA, PackedRotationRate& rB, PackedRotationRate& rC, uint32 syncStamp = 0);

	ShipUpdateTransformMessage(ShipObject* ship, const Vector3& position, PackedVelocity& velocity, uint32 syncStamp = 0);

	void writePackedPosition(const Vector3& position);

	void writePackedDirection(const Quaternion* direction);
};
