#include "Not.h"

Not::Not(const String& className, const uint32 id, const LuaObject& args) : Decorator(className, id, args) {
}

Not::Not(const Not& b) : Decorator(b) {
}

Behavior::Status Not::execute(AiAgent* agent, unsigned int startIdx) const {
	assert(child != nullptr);

	Behavior::Status result = child->doAction(agent);

	if (result == FAILURE)
		return SUCCESS;

	if (result == SUCCESS)
		return FAILURE;

	return result;
}