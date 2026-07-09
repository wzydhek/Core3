#include "AlwaysSucceedSpace.h"

AlwaysSucceedSpace::AlwaysSucceedSpace(const String& className, const uint32 id, const LuaObject& args) : DecoratorSpace(className, id, args) {
}

AlwaysSucceedSpace::AlwaysSucceedSpace(const AlwaysSucceedSpace& b) : DecoratorSpace(b) {
}

BehaviorSpace::Status AlwaysSucceedSpace::execute(ShipAiAgent* agent, unsigned int startIdx) const {
	assert(child != nullptr);

	BehaviorSpace::Status result = child->doAction(agent);

	if (result == RUNNING)
		agent->clearRunningChain();

	if (result == SUCCESS || result == FAILURE || result == RUNNING)
		return SUCCESS;

	return result;
}