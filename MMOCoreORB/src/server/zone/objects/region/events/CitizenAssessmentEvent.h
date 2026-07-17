#pragma once

#include "server/zone/ZoneServer.h"

namespace server {
	namespace zone {
		namespace objects {
			namespace region {
				class CityRegion;
			}
		}
	}
}

namespace server {
namespace zone {
namespace objects {
namespace region {
namespace events {

	class CitizenAssessmentEvent : public Task {
	Reference<ZoneServer*> zoneServer;
	WeakReference<server::zone::objects::region::CityRegion*> cityRegion;

public:
	CitizenAssessmentEvent(server::zone::objects::region::CityRegion* city, ZoneServer* zserv);

	void run();
};

} // namespace events
} // namespace region
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::region::events;
