/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "engine/service/proto/BaseMessage.h"
#include "server/zone/objects/tangible/TangibleObject.h"

class UpdatePVPStatusMessage : public BaseMessage {
public:
	UpdatePVPStatusMessage(TangibleObject* tano);

	UpdatePVPStatusMessage(TangibleObject* tano, TangibleObject* receiver, uint32 pvpStatusBitmask);
};
