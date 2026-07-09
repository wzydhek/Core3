#include "EmoteReactionFine.h"

EmoteReactionFine::EmoteReactionFine(int level, bool imperial, bool human, int rankCompare, int creditamount, int factionamount, bool knockdown, int minquip, int maxquip, String emoterespond) : Object() {
	reactionLevel = level;
	isImp = imperial;
	isHumanSpecies = human;
	rankComparison = rankCompare;
	creditFine = creditamount;
	factionFine = factionamount;
	doKnockdown = knockdown;
	minQuip = minquip;
	maxQuip = maxquip;
	emoteResponse = emoterespond;
}

EmoteReactionFine::~EmoteReactionFine() {
}

String EmoteReactionFine::getEmoteResponse() {
	return emoteResponse;
}

bool EmoteReactionFine::isImperial() {
	return isImp;
}

bool EmoteReactionFine::isHuman() {
	return isHumanSpecies;
}

bool EmoteReactionFine::shouldKnockdown() {
	return doKnockdown;
}

int EmoteReactionFine::getRankComparison() {
	return rankComparison;
}

int EmoteReactionFine::getReactionLevel() {
	return reactionLevel;
}

int EmoteReactionFine::getCreditFine() {
	return creditFine;
}

int EmoteReactionFine::getFactionFine() {
	return factionFine;
}

int EmoteReactionFine::getRandomQuip() {
	if (maxQuip == -1 || minQuip == -1)
		return -1;

	return minQuip + System::random(maxQuip - minQuip);
}