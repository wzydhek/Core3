#pragma once

#include "server/zone/objects/creature/ai/bt/Behavior.h"
#include "server/zone/objects/creature/ai/bt/BehaviorTreeSlot.h"
#include "server/zone/objects/creature/ai/AiAgent.h"

namespace server {
namespace zone {
namespace objects {
namespace creature {
namespace ai {
namespace bt {

class TreeSocket : public Behavior {
protected:
	BehaviorTreeSlot slotID;

public:
	TreeSocket(const String& className, const uint32 id, const LuaObject& args);

	TreeSocket(const TreeSocket& b);

	TreeSocket& operator=(const TreeSocket& b);

	bool isSocket() const;

	Behavior::Status execute(AiAgent* agent, unsigned int startIdx = 0) const;

	void parseArgs(const LuaObject& args);

	String print() const;

	const BehaviorTreeSlot& getSlotID() const;
};

} // namespace bt
} // namespace ai
} // namespace creature
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::creature::ai::bt;
