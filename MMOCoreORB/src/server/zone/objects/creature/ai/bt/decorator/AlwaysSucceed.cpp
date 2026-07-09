#include "AlwaysSucceed.h"
#include "server/zone/objects/creature/ai/AiAgent.h"

AlwaysSucceed::AlwaysSucceed(const String& className, const uint32 id, const LuaObject& args) : Decorator(className, id, args) {
}

AlwaysSucceed::AlwaysSucceed(const AlwaysSucceed& b) : Decorator(b) {
}

Behavior::Status AlwaysSucceed::execute(AiAgent* agent, unsigned int startIdx) const {
	assert(child != nullptr);

	Behavior::Status result = child->doAction(agent);

	if (result == RUNNING)
		agent->clearRunningChain();

	if (result == SUCCESS || result == FAILURE || result == RUNNING)
		return SUCCESS;

	return result;
}