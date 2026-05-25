/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "engine/service/proto/BaseMessage.h"
#include "server/zone/objects/tangible/TangibleObject.h"

class UpdatePVPStatusMessage : public BaseMessage {
public:
	UpdatePVPStatusMessage(TangibleObject* tano) : BaseMessage() {
		insertShort(0x04);
		insertInt(0x08A1C126);  //UpdatePVPStatusMessage
		insertInt(tano->getPvpStatusBitmask());
		insertInt(tano->getFaction());
		insertLong(tano->getObjectID());
	}

	UpdatePVPStatusMessage(TangibleObject* tano, TangibleObject* receiver, uint32 pvpStatusBitmask) : BaseMessage() {
		insertShort(0x04);
		insertInt(0x08A1C126);  //UpdatePVPStatusMessage
		insertInt(pvpStatusBitmask);

		unsigned int faction = 0;
		if (!tano->isPlayerCreature() || tano->getFaction() == receiver->getFaction() || pvpStatusBitmask & ObjectFlag::OVERT) {
			faction = tano->getFaction();
		}

		insertInt(faction);
		insertLong(tano->getObjectID());
	}
};
