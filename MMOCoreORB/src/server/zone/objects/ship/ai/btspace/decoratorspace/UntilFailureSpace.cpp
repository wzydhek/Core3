#include "UntilFailureSpace.h"

UntilFailureSpace::UntilFailureSpace(const String& className, const uint32 id, const LuaObject& args) : DecoratorSpace(className, id, args) {
}

UntilFailureSpace::UntilFailureSpace(const UntilFailureSpace& b) : DecoratorSpace(b) {
}

BehaviorSpace::Status UntilFailureSpace::execute(ShipAiAgent* agent, unsigned int startIdx) const {
	assert(child != nullptr);

	BehaviorSpace::Status result = child->doAction(agent);

	while (result == SUCCESS) {
		result = child->doAction(agent);
	}

	return result;
}