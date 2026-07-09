/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "engine/engine.h"
#include "server/zone/objects/mission/MissionTypes.h"
#include "engine/util/Singleton.h"
#include "system/thread/atomic/AtomicLong.h"
#include "engine/log/Logger.h"
#include "server/zone/managers/creature/AiMap.h"
#include "server/zone/managers/space/SpaceAiMap.h"

class StatisticsManager : public Singleton<StatisticsManager>, public Logger, public Object {
	const static int CONSOLE_REPORT_INTERVAL = 1000;

	AtomicLong numberOfCompletedMissionsBounty;
	AtomicLong numberOfCompletedMissionsCrafting;
	AtomicLong numberOfCompletedMissionsDancer;
	AtomicLong numberOfCompletedMissionsDeliver;
	AtomicLong numberOfCompletedMissionsDestroy;
	AtomicLong numberOfCompletedMissionsHunting;
	AtomicLong numberOfCompletedMissionsMusician;
	AtomicLong numberOfCompletedMissionsRecon;
	AtomicLong numberOfCompletedMissionsSurvey;
	AtomicLong creditsGeneratedFromMissionsBounty;
	AtomicLong creditsGeneratedFromMissionsCrafting;
	AtomicLong creditsGeneratedFromMissionsDancer;
	AtomicLong creditsGeneratedFromMissionsDeliver;
	AtomicLong creditsGeneratedFromMissionsDestroy;
	AtomicLong creditsGeneratedFromMissionsHunting;
	AtomicLong creditsGeneratedFromMissionsMusician;
	AtomicLong creditsGeneratedFromMissionsRecon;
	AtomicLong creditsGeneratedFromMissionsSurvey;

	pid_t corePid;
	Time coreStartTime;
	Time coreInitializedTime;

	Mutex mutex;
	Time lastReset;

	uint16 accountsCount;
	uint16 accountsMax;
	Time accountsMaxWhen;

	uint16 onlineCount;
	uint16 onlineMax;
	Time onlineMaxWhen;

	uint16 distinctIPsCount;
	uint16 distinctIPsMax;
	Time distinctIPsMaxWhen;

public:
	StatisticsManager();

	void markCoreStart(pid_t pid);

	void markCoreInitialized();

	void setAccountsCount(uint16 count);

	void setOnlineCount(uint16 count);

	void setDistinctIPsCount(uint16 count);

	void completeMission(unsigned int missionType, int reward);

	String getStatistics();

	const JSONSerializationType getAsJSON();

	void reset();

private:
	void resetMissionStatistics();
};
