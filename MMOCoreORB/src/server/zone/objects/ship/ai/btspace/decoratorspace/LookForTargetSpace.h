#pragma once

#include "server/zone/objects/ship/ai/ShipAiAgent.h"
#include "server/zone/objects/ship/ai/btspace/decoratorspace/DecoratorSpace.h"
#include "templates/params/creature/ObjectFlag.h"
#include <cassert>

namespace server {
namespace zone {
namespace objects {
namespace ship {
namespace ai {
namespace btspace {
namespace decoratorspace {

class LookForTargetSpace : public DecoratorSpace {
public:
	LookForTargetSpace(const String& className, const uint32 id, const LuaObject& args);

	LookForTargetSpace(const LookForTargetSpace& b);

	BehaviorSpace::Status execute(ShipAiAgent* agent, unsigned int startIdx = 0) const;

	bool isInvalidTarget(ShipObject* targetShip, ShipAiAgent* agent) const;
};

} // namespace decoratorspace
} // namespace btspace
} // namespace ai
} // namespace ship
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::ship::ai::btspace::decoratorspace;