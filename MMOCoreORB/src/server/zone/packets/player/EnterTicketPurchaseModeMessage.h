/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "engine/service/proto/BaseMessage.h"
#include "server/zone/managers/planet/PlanetTravelPoint.h"

class EnterTicketPurchaseModeMessage : public BaseMessage {
public:
    EnterTicketPurchaseModeMessage(PlanetTravelPoint* ptp) {
		insertShort(0x04);
		insertInt(0x904DAE1A);  // CRC
        insertAscii(ptp->getPointZone());
        insertAscii(ptp->getPointName());
        insertByte(0);
    }
};
