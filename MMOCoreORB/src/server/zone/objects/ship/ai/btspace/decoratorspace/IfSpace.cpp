#include "IfSpace.h"

IfSpace::IfSpace(const String& className, const uint32 id, const LuaObject& args) : DecoratorSpace(className, id, args) {
}

IfSpace::IfSpace(const IfSpace& b) : DecoratorSpace(b) {
}

BehaviorSpace::Status IfSpace::execute(ShipAiAgent* agent, unsigned int startIdx) const {
	assert(child != nullptr);

	return child->doAction(agent);
}