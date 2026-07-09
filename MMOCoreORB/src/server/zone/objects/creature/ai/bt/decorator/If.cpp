#include "If.h"

If::If(const String& className, const uint32 id, const LuaObject& args) : Decorator(className, id, args) {
}

If::If(const If& b) : Decorator(b) {
}

Behavior::Status If::execute(AiAgent* agent, unsigned int startIdx) const {
	assert(child != nullptr);

	return child->doAction(agent);
}