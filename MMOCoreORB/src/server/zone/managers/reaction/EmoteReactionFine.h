
#pragma once

#include "system/lang/Object.h"
#include "system/lang/String.h"

namespace server {
namespace zone {
namespace managers {
namespace reaction {

class EmoteReactionFine : public Object {

protected:
	int reactionLevel, rankComparison, creditFine, factionFine, minQuip, maxQuip;
	bool isImp, isHumanSpecies, doKnockdown;
	String emoteResponse;

public:
	EmoteReactionFine(int level, bool imperial, bool human, int rankCompare, int creditamount, int factionamount, bool knockdown, int minquip, int maxquip, String emoterespond);

	~EmoteReactionFine();

	String getEmoteResponse();

	bool isImperial();

	bool isHuman();

	bool shouldKnockdown();

	int getRankComparison();

	int getReactionLevel();

	int getCreditFine();

	int getFactionFine();

	int getRandomQuip();

};

}
}
}
}

using namespace server::zone::managers::reaction;
