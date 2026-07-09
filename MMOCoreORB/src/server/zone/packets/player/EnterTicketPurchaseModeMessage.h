/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "engine/service/proto/BaseMessage.h"
#include "server/zone/managers/planet/PlanetTravelPoint.h"

class EnterTicketPurchaseModeMessage : public BaseMessage {
public:
	EnterTicketPurchaseModeMessage(PlanetTravelPoint* ptp);
};
