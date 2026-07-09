#include "AlwaysFail.h"
#include "server/zone/objects/creature/ai/AiAgent.h"

AlwaysFail::AlwaysFail(const String& className, const uint32 id, const LuaObject& args) : Decorator(className, id, args) {
}

AlwaysFail::AlwaysFail(const AlwaysFail& b) : Decorator(b) {
}

Behavior::Status AlwaysFail::execute(AiAgent* agent, unsigned int startIdx) const {
	assert(child != nullptr);

	Behavior::Status result = child->doAction(agent);

	if (result == RUNNING)
		agent->clearRunningChain();

	if (result == SUCCESS || result == FAILURE || result == RUNNING)
		return FAILURE;

	return result;
}