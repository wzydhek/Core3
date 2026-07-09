#include "StatisticsManager.h"

StatisticsManager::StatisticsManager() : Logger("StatisticsManager") {
	reset();
}

void StatisticsManager::markCoreStart(pid_t pid) {
	Locker guard(&mutex);
	corePid = pid;
	coreStartTime.updateToCurrentTime();
}

void StatisticsManager::markCoreInitialized() {
	Locker guard(&mutex);
	coreInitializedTime.updateToCurrentTime();
}

void StatisticsManager::setAccountsCount(uint16 count) {
	Locker guard(&mutex);

	accountsCount = count;

	if (accountsCount > accountsMax) {
		accountsMax = accountsCount;
		accountsMaxWhen.updateToCurrentTime();
	}
}

void StatisticsManager::setOnlineCount(uint16 count) {
	Locker guard(&mutex);

	onlineCount = count;

	if (onlineCount > onlineMax) {
		onlineMax = onlineCount;
		onlineMaxWhen.updateToCurrentTime();
	}
}

void StatisticsManager::setDistinctIPsCount(uint16 count) {
	Locker guard(&mutex);

	distinctIPsCount = count;

	if (distinctIPsCount > distinctIPsMax) {
		distinctIPsMax = distinctIPsCount;
		distinctIPsMaxWhen.updateToCurrentTime();
	}
}

void StatisticsManager::completeMission(unsigned int missionType, int reward) {
	switch (missionType) {
		case MissionTypes::BOUNTY:
			numberOfCompletedMissionsBounty.increment();
			creditsGeneratedFromMissionsBounty.add(reward);
			break;
		case MissionTypes::CRAFTING:
			numberOfCompletedMissionsCrafting.increment();
			creditsGeneratedFromMissionsCrafting.add(reward);
			break;
		case MissionTypes::DANCER:
			numberOfCompletedMissionsDancer.increment();
			creditsGeneratedFromMissionsDancer.add(reward);
			break;
		case MissionTypes::DELIVER:
			numberOfCompletedMissionsDeliver.increment();
			creditsGeneratedFromMissionsDeliver.add(reward);
			break;
		case MissionTypes::DESTROY:
			numberOfCompletedMissionsDestroy.increment();
			creditsGeneratedFromMissionsDestroy.add(reward);
			break;
		case MissionTypes::HUNTING:
			numberOfCompletedMissionsHunting.increment();
			creditsGeneratedFromMissionsHunting.add(reward);
			break;
		case MissionTypes::MUSICIAN:
			numberOfCompletedMissionsMusician.increment();
			creditsGeneratedFromMissionsMusician.add(reward);
			break;
		case MissionTypes::RECON:
			numberOfCompletedMissionsRecon.increment();
			creditsGeneratedFromMissionsRecon.add(reward);
			break;
		case MissionTypes::SURVEY:
			numberOfCompletedMissionsSurvey.increment();
			creditsGeneratedFromMissionsSurvey.add(reward);
			break;
	}
}

String StatisticsManager::getStatistics() {
	return String(getAsJSON().dump(2));
}

const JSONSerializationType StatisticsManager::getAsJSON() {
	Locker guard(&mutex);

	JSONSerializationType json = JSONSerializationType::object();

	JSONSerializationType state;

	state["elapsedMs"] = lastReset.miliDifference();
	state["lastResetTime"] = lastReset.getFormattedTimeFull();
	state["lastResetTimeMs"] = lastReset;

	json["state"] = state;

	auto aimap = AiMap::instance();

	if (aimap != nullptr) {
		json["ai"] = aimap->getStatsAsJSON();
	}

	auto spaceAiMap = SpaceAiMap::instance();

	if (spaceAiMap != nullptr) {
		json["spaceAi"] = spaceAiMap->getStatsAsJSON();
	}

	JSONSerializationType core;

	core["pid"] = corePid;
	core["coreStartTime"] = coreStartTime.getFormattedTimeFull();
	core["coreStartTimeMs"] = coreStartTime;
	core["coreInitializedTime"] = coreInitializedTime.getFormattedTimeFull();
	core["coreInitializedTimeMs"] = coreInitializedTime;
	core["coreLoadMs"] = coreStartTime.miliDifference(coreInitializedTime);

	json["core"] = core;

	JSONSerializationType players;

	players["accountsCount"] = accountsCount;
	players["accountsMax"] = accountsMax;
	players["accountsMaxWhen"] = accountsMaxWhen.getFormattedTimeFull();
	players["accountsMaxWhenMs"] = accountsMaxWhen;
	players["distinctIPsCount"] = distinctIPsCount;
	players["distinctIPsMax"] = distinctIPsMax;
	players["distinctIPsMaxWhen"] = distinctIPsMaxWhen.getFormattedTimeFull();
	players["distinctIPsMaxWhenMs"] = distinctIPsMaxWhen;
	players["onlineCount"] = onlineCount;
	players["onlineMax"] = onlineMax;
	players["onlineMaxWhen"] = onlineMaxWhen.getFormattedTimeFull();
	players["onlineMaxWhenMs"] = onlineMaxWhen;

	json["players"] = players;

	JSONSerializationType missions;

	missions["creditsGeneratedFromMissionsBounty"] = creditsGeneratedFromMissionsBounty.get();
	missions["creditsGeneratedFromMissionsCrafting"] = creditsGeneratedFromMissionsCrafting.get();
	missions["creditsGeneratedFromMissionsDancer"] = creditsGeneratedFromMissionsDancer.get();
	missions["creditsGeneratedFromMissionsDeliver"] = creditsGeneratedFromMissionsDeliver.get();
	missions["creditsGeneratedFromMissionsDestroy"] = creditsGeneratedFromMissionsDestroy.get();
	missions["creditsGeneratedFromMissionsHunting"] = creditsGeneratedFromMissionsHunting.get();
	missions["creditsGeneratedFromMissionsMusician"] = creditsGeneratedFromMissionsMusician.get();
	missions["creditsGeneratedFromMissionsRecon"] = creditsGeneratedFromMissionsRecon.get();
	missions["creditsGeneratedFromMissionsSurvey"] = creditsGeneratedFromMissionsSurvey.get();
	missions["numberOfCompletedMissionsBounty"] = numberOfCompletedMissionsBounty.get();
	missions["numberOfCompletedMissionsCrafting"] = numberOfCompletedMissionsCrafting.get();
	missions["numberOfCompletedMissionsDancer"] = numberOfCompletedMissionsDancer.get();
	missions["numberOfCompletedMissionsDeliver"] = numberOfCompletedMissionsDeliver.get();
	missions["numberOfCompletedMissionsDestroy"] = numberOfCompletedMissionsDestroy.get();
	missions["numberOfCompletedMissionsHunting"] = numberOfCompletedMissionsHunting.get();
	missions["numberOfCompletedMissionsMusician"] = numberOfCompletedMissionsMusician.get();
	missions["numberOfCompletedMissionsRecon"] = numberOfCompletedMissionsRecon.get();
	missions["numberOfCompletedMissionsSurvey"] = numberOfCompletedMissionsSurvey.get();

	json["missionStats"] = missions;

	return json;
}

void StatisticsManager::reset() {
	Locker guard(&mutex);

	resetMissionStatistics();

	accountsCount = 0;
	accountsMax = 0;
	accountsMaxWhen.updateToCurrentTime();

	distinctIPsCount = 0;
	distinctIPsMax = 0;
	distinctIPsMaxWhen.updateToCurrentTime();

	onlineCount = 0;
	onlineMax = 0;
	onlineMaxWhen.updateToCurrentTime();

	lastReset.updateToCurrentTime();
}

void StatisticsManager::resetMissionStatistics() {
	numberOfCompletedMissionsBounty = 0;
	numberOfCompletedMissionsCrafting = 0;
	numberOfCompletedMissionsDancer = 0;
	numberOfCompletedMissionsDeliver = 0;
	numberOfCompletedMissionsDestroy = 0;
	numberOfCompletedMissionsHunting = 0;
	numberOfCompletedMissionsMusician = 0;
	numberOfCompletedMissionsRecon = 0;
	numberOfCompletedMissionsSurvey = 0;
	creditsGeneratedFromMissionsBounty = 0;
	creditsGeneratedFromMissionsCrafting = 0;
	creditsGeneratedFromMissionsDancer = 0;
	creditsGeneratedFromMissionsDeliver = 0;
	creditsGeneratedFromMissionsDestroy = 0;
	creditsGeneratedFromMissionsHunting = 0;
	creditsGeneratedFromMissionsMusician = 0;
	creditsGeneratedFromMissionsRecon = 0;
	creditsGeneratedFromMissionsSurvey = 0;
}