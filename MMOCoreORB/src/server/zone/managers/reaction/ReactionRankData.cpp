#include "ReactionRankData.h"

ReactionRankData::ReactionRankData(String name, int min, int max) : Object() {
	templateName = name;
	minRank = min;
	maxRank = max;
}

ReactionRankData::~ReactionRankData() {
}

String ReactionRankData::getTemplateName() {
	return templateName;
}

int ReactionRankData::getRandomRank() {
	return minRank + System::random(maxRank - minRank);
}