#pragma once

#include "system/lang/Object.h"
#include "system/lang/String.h"

namespace server {
namespace zone {
namespace managers {
namespace frs {

class FrsRankingData : public Object {

protected:
	int rank, requiredXp, playerCap;
	String skillName, robeTemplate;

public:
	FrsRankingData(int frsRank, String skill, int reqExp, int cap, String robeTemp);

	~FrsRankingData();

	int getRequiredExperience() const;

	int getPlayerCap() const;

	int getRank() const;

	const String& getSkillName() const;

	const String& getRobeTemplate() const;

};

}
}
}
}

using namespace server::zone::managers::frs;
