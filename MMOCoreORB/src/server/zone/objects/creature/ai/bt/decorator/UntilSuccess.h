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

class UntilSuccess : public Decorator {
public:
	UntilSuccess(const String& className, const uint32 id, const LuaObject& args);

	UntilSuccess(const UntilSuccess& b);

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
