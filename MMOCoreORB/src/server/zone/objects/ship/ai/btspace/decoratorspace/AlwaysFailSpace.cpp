#include "AlwaysFailSpace.h"

AlwaysFailSpace::AlwaysFailSpace(const String& className, const uint32 id, const LuaObject& args) : DecoratorSpace(className, id, args) {
}

AlwaysFailSpace::AlwaysFailSpace(const AlwaysFailSpace& b) : DecoratorSpace(b) {
}

BehaviorSpace::Status AlwaysFailSpace::execute(ShipAiAgent* agent, unsigned int startIdx) const {
	assert(child != nullptr);

	BehaviorSpace::Status result = child->doAction(agent);

	if (result == RUNNING)
		agent->clearRunningChain();

	if (result == SUCCESS || result == FAILURE || result == RUNNING)
		return FAILURE;

	return result;
}