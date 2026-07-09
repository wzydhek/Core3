/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "server/zone/packets/BaseLineMessage.h"
#include "server/zone/objects/building/BuildingObject.h"

class BuildingObjectMessage6 : public BaseLineMessage {
public:
	BuildingObjectMessage6(BuildingObject *buio);
};
