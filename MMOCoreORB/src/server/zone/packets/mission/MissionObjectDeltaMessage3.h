/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "server/zone/packets/DeltaMessage.h"
#include "server/zone/objects/mission/MissionObject.h"
#include "server/zone/objects/waypoint/WaypointObject.h"

class MissionObjectDeltaMessage3 : public DeltaMessage {
	MissionObject* miso;

public:
	MissionObjectDeltaMessage3(MissionObject* mi);

	void updateDescriptionStf(StringId* stringId);

	void updateTitleStf(StringId* stringId);

	void updateTargetName(const String& name);

	void updateDifficultyLevel(int diff);

	void updateRewardCredits(int creds);

	void updateRefreshCount(uint32 trc);

	void updateTypeCRC(uint32 crc);

	void updateTemplateCRC(uint32 crc);

	void updateStartPosition(float posX, float posZ, float posY, uint32 crc);

	void updateDestination(float posX, float posZ, float posY, uint32 crc);

	void updateCreator();

	void updateWaypoint(WaypointObject* way);

};
