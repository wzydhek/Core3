#pragma once

#include "server/zone/objects/ship/ai/btspace/BehaviorSpace.h"
#include "server/zone/objects/ship/ai/btspace/BehaviorTreeSlotSpace.h"
#include "server/zone/objects/ship/ai/ShipAiAgent.h"

namespace server {
namespace zone {
namespace objects {
namespace ship {
namespace ai {
namespace btspace {

class TreeSocketSpace : public BehaviorSpace {
protected:
	BehaviorTreeSlotSpace slotID;

public:
	TreeSocketSpace(const String& className, const uint32 id, const LuaObject& args);

	TreeSocketSpace(const TreeSocketSpace& b);

	TreeSocketSpace& operator=(const TreeSocketSpace& b);

	bool isSocketSpace() const;

	BehaviorSpace::Status execute(ShipAiAgent* agent, unsigned int startIdx = 0) const;

	void parseArgs(const LuaObject& args);

	String print() const;

	const BehaviorTreeSlotSpace& getSlotID() const;
};

} // namespace btspace
} // namespace ai
} // namespace ship
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::ship::ai::btspace;
