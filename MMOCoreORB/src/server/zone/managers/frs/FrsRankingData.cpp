#include "FrsRankingData.h"

FrsRankingData::FrsRankingData(int frsRank, String skill, int reqExp, int cap, String robeTemp) : Object() {
	rank = frsRank;
	skillName = skill;
	requiredXp = reqExp;
	playerCap = cap;
	robeTemplate = robeTemp;
}

FrsRankingData::~FrsRankingData() {
}

int FrsRankingData::getRequiredExperience() const {
	return requiredXp;
}

int FrsRankingData::getPlayerCap() const {
	return playerCap;
}

int FrsRankingData::getRank() const {
	return rank;
}

const String& FrsRankingData::getSkillName() const {
	return skillName;
}

const String& FrsRankingData::getRobeTemplate() const {
	return robeTemplate;
}