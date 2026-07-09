#include "UntilFailure.h"

UntilFailure::UntilFailure(const String& className, const uint32 id, const LuaObject& args) : Decorator(className, id, args) {
}

UntilFailure::UntilFailure(const UntilFailure& b) : Decorator(b) {
}

Behavior::Status UntilFailure::execute(AiAgent* agent, unsigned int startIdx) const {
	assert(child != nullptr);

	Behavior::Status result = child->doAction(agent);
	while (result == SUCCESS) {
		result = child->doAction(agent);
	}

	return result;
}