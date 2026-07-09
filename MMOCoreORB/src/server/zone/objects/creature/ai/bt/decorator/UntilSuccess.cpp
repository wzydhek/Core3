#include "UntilSuccess.h"

UntilSuccess::UntilSuccess(const String& className, const uint32 id, const LuaObject& args) : Decorator(className, id, args) {
}

UntilSuccess::UntilSuccess(const UntilSuccess& b) : Decorator(b) {
}

Behavior::Status UntilSuccess::execute(AiAgent* agent, unsigned int startIdx) const {
	assert(child != nullptr);

	Behavior::Status result = child->doAction(agent);
	while (result == FAILURE) {
		result = child->doAction(agent);
	}

	return result;
}