/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "engine/service/proto/BaseMessage.h"

class EnterStructurePlacementModeMessage : public BaseMessage {
public:
	EnterStructurePlacementModeMessage(uint64 deedid, String crcpath);
};
