
#pragma once

#include "templates/tangible/DeedTemplate.h"

namespace templates {
namespace tangible {

class EventPerkDeedTemplate : public DeedTemplate {
private:
	int perkType;
	uint64 generatedTimeToLive;
	SortedVector<String> allowedZones;

public:
	const static int UNKNOWN = 0;
	const static int STATIC = 1;
	const static int THEATER = 2;
	const static int RECRUITER = 3;
	const static int GAME = 4;
	const static int HONORGUARD = 5;
	const static int NPCACTOR = 6;

	const static uint64 TIME_TO_LIVE = 28800000; // 8 hours

	EventPerkDeedTemplate();

	~EventPerkDeedTemplate();

	void readObject(LuaObject* templateData);

	int getPerkType();

	uint64 getGeneratedTimeToLive();

	bool isAllowedZone(const String& zoneName);

};

} // namespace tangible
} // namespace templates

using namespace templates::tangible;
