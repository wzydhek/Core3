#pragma once

#include "server/zone/objects/ship/ai/btspace/decoratorspace/DecoratorSpace.h"
#include <cassert>

namespace server {
namespace zone {
namespace objects {
namespace ship {
namespace ai {
namespace btspace {
namespace decoratorspace {

class UntilFailureSpace : public DecoratorSpace {
public:
	UntilFailureSpace(const String& className, const uint32 id, const LuaObject& args);

	UntilFailureSpace(const UntilFailureSpace& b);

	BehaviorSpace::Status execute(ShipAiAgent* agent, unsigned int startIdx = 0) const;
};

} // namespace decoratorspace
} // namespace btspace
} // namespace ai
} // namespace ship
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::ship::ai::btspace::decoratorspace;