#pragma once

#include "system/util/VectorMap.h"
#include "BlackboardData.h"

namespace server {
namespace zone {
namespace objects {
namespace creature {
namespace ai {
namespace bt {

class BlackboardDataMap : public VectorMap<String, BlackboardData> {
public:
	BlackboardDataMap();

	BlackboardDataMap(const BlackboardDataMap& b);

	~BlackboardDataMap();

	BlackboardDataMap& operator=(const BlackboardDataMap& b);
};

}
}
}
}
}
}

using namespace server::zone::objects::creature::ai::bt;
