#pragma once

#include "server/zone/objects/creature/ai/bt/decorator/Decorator.h"
#include <cassert>

namespace server {
namespace zone {
namespace objects {
namespace creature {
namespace ai {
namespace bt {
namespace decorator {

class UntilFailure : public Decorator {
public:
	UntilFailure(const String& className, const uint32 id, const LuaObject& args);

	UntilFailure(const UntilFailure& b);

	Behavior::Status execute(AiAgent* agent, unsigned int startIdx = 0) const;
};

}
}
}
}
}
}
}

using namespace server::zone::objects::creature::ai::bt::decorator;
