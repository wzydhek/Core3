/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "server/zone/packets/BaseLineMessage.h"
#include "server/zone/objects/mission/MissionObject.h"

class MissionObjectMessage6 : public BaseLineMessage {
public:
	MissionObjectMessage6(MissionObject* mi);
};
