#pragma once

#include "engine/engine.h"

class ShipDroidData {
public:
	enum DroidType : int {
			NONE = 0,
			ASTROMECH = 1,
			FLIGHTCOMPUTER = 2
	};

	static uint32 getShipDroidType(uint32 shipNameCRC);

	static uint32 getDroidType(uint32 droidCrc);
};
