/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "../BaseLineMessage.h"
#include "server/zone/objects/ship/ShipObject.h"

class ShipObjectMessage3 : public BaseLineMessage {
protected:
	enum index : int {
		complexity = 0,
		objectName = 1,
		customObjectName = 2,
		volume = 3,
		customizationString = 4,
		visibleComponents = 5,
		optionsBitmask = 6,
		useCount = 7,
		condition = 8,
		conditionMax = 9,
		visible = 10,
		chassisSlideFactor = 11,
		chassisCurrentHealth = 12,
		chassisMaxHealth = 13,
		chassisTypeCRC = 14,
		componentMaxArmorMap = 15,
		componentCurrentArmorMap = 16,
		componentCurrentHitpointsMap = 17,
		componentMaxHitpointsMap = 18,
		componentOptionsMap = 19,
		maxFrontShield = 20,
		maxRearShield = 21
	};

public:
	ShipObjectMessage3(ShipObject* ship);

	UnicodeString getShipName(ShipObject* ship);
};
