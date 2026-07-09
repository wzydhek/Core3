#pragma once

#include "server/zone/objects/creature/ai/AiAgent.h"
#include "templates/params/OptionBitmask.h"
#include "templates/params/creature/ObjectFlag.h"
#include "server/zone/objects/creature/ai/bt/decorator/Decorator.h"
#include "server/zone/managers/collision/CollisionManager.h"
#include <cassert>

namespace server {
namespace zone {
namespace objects {
namespace creature {
namespace ai {
namespace bt {
namespace decorator {

class LookForTarget : public Decorator {
public:
	LookForTarget(const String& className, const uint32 id, const LuaObject& args);

	LookForTarget(const LookForTarget& b);

	Behavior::Status execute(AiAgent* agent, unsigned int startIdx = 0) const;

	bool isInvalidTarget(CreatureObject* target, AiAgent* agent) const;
};

}
}
}
}
}
}
}

using namespace server::zone::objects::creature::ai::bt::decorator;
