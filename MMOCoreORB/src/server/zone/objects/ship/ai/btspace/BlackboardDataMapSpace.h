#pragma once

#include "system/util/VectorMap.h"
#include "BlackboardDataSpace.h"

namespace server {
namespace zone {
namespace objects {
namespace ship {
namespace ai {
namespace btspace {

class BlackboardDataMapSpace : public VectorMap<String, BlackboardDataSpace> {
public:
	BlackboardDataMapSpace();

	BlackboardDataMapSpace(const BlackboardDataMapSpace& b);

	~BlackboardDataMapSpace();

	BlackboardDataMapSpace& operator=(const BlackboardDataMapSpace& b);
};

} // namespace btspace
} // namespace ai
} // namespace ship
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::ship::ai::btspace;