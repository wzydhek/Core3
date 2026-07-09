
#pragma once

#include "system/lang/Object.h"
#include "system/lang/String.h"

namespace server {
namespace zone {
namespace managers {
namespace reaction {

class ReactionRankData : public Object {

protected:
	int minRank, maxRank;
	String templateName;

public:
	ReactionRankData(String name, int min, int max);

	~ReactionRankData();

	String getTemplateName();

	int getRandomRank();

};

}
}
}
}

using namespace server::zone::managers::reaction;
