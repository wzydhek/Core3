/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "../BaseLineMessage.h"
#include "server/zone/objects/ship/ShipObject.h"

class ShipObjectMessage6 : public BaseLineMessage {
protected:
	enum index : int {
		flags = 0,
		defenders = 1,
		uniqueID = 2,
		actualAccelerationRate = 3,
		actualDecelerationRate = 4,
		actualPitchAccelerationRate = 5,
		actualYawAccelerationRate = 6,
		actualRollAccelerationRate = 7,
		actualPitchRate = 8,
		actualYawRate = 9,
		actualRollRate = 10,
		actualMaxSpeed = 11,
		targetID = 12,
		targetIDSlot = 13,
		targetableBitfield = 14,
		shipComponentMap = 15,
		wingName = 16,
		typeName = 17,
		difficulty = 18,
		faction = 19,
		frontShield = 20,
		rearShield = 21,
		guildId = 22,
	};

public:
	ShipObjectMessage6(ShipObject* ship);

	int getGuildID(ShipObject* ship);

	String getShipTypeName(ShipObject* ship);
};
