#include "UntilSuccessSpace.h"

UntilSuccessSpace::UntilSuccessSpace(const String& className, const uint32 id, const LuaObject& args) : DecoratorSpace(className, id, args) {
}

UntilSuccessSpace::UntilSuccessSpace(const UntilSuccessSpace& b) : DecoratorSpace(b) {
}

BehaviorSpace::Status UntilSuccessSpace::execute(ShipAiAgent* agent, unsigned int startIdx) const {
	assert(child != nullptr);

	BehaviorSpace::Status result = child->doAction(agent);

	while (result == FAILURE) {
		result = child->doAction(agent);
	}

	return result;
}