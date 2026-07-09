/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "engine/service/proto/BaseMessage.h"
#include "server/zone/managers/planet/MapLocationTable.h"

class GetMapLocationsResponseMessage : public BaseMessage {
public:
	GetMapLocationsResponseMessage(const String& planet, const MapLocationTable* mapLocations, CreatureObject* player);

};
