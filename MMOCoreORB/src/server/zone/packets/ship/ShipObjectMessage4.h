/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "server/zone/packets/BaseLineMessage.h"
#include "server/zone/objects/ship/ShipObject.h"

class ShipObjectMessage4 : public BaseLineMessage {
protected:
	enum index : int {
		currentMass = 0,
		chassisSpeed = 1,
		capacitorEnergy = 2,
		boosterEnergy = 3,
		componentRefireEfficiency = 4
	};

public:
	ShipObjectMessage4(ShipObject* ship);
};
