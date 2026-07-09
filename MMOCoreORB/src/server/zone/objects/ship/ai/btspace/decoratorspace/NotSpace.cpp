#include "NotSpace.h"

NotSpace::NotSpace(const String& className, const uint32 id, const LuaObject& args) : DecoratorSpace(className, id, args) {
}

NotSpace::NotSpace(const NotSpace& b) : DecoratorSpace(b) {
}

BehaviorSpace::Status NotSpace::execute(ShipAiAgent* agent, unsigned int startIdx) const {
	assert(child != nullptr);

	BehaviorSpace::Status result = child->doAction(agent);

	if (result == FAILURE)
		return SUCCESS;

	if (result == SUCCESS)
		return FAILURE;

	return result;
}