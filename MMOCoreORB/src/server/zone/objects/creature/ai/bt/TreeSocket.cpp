#include "TreeSocket.h"

TreeSocket::TreeSocket(const String& className, const uint32 id, const LuaObject& args) : Behavior(className, id, args), slotID(BehaviorTreeSlot::NONE) {
	parseArgs(args);
}

TreeSocket::TreeSocket(const TreeSocket& b) : Behavior(b), slotID(b.slotID) {
}

TreeSocket& TreeSocket::operator=(const TreeSocket& b) {
	if (this == &b)
		return *this;

	Behavior::operator=(b);
	slotID = b.slotID;
	return *this;
}

bool TreeSocket::isSocket() const {
	return true;
}

Behavior::Status TreeSocket::execute(AiAgent* agent, unsigned int startIdx) const {
	const Behavior* child = agent->getBehaviorTree(slotID);

	if (child == nullptr)
		return FAILURE;

	return child->doAction(agent);
}

void TreeSocket::parseArgs(const LuaObject& args) {
	slotID = getArg<BehaviorTreeSlot>()(args, "slot");
}

String TreeSocket::print() const {
	StringBuffer msg;
	msg << className << "-" << getBehaviorTreeSlotName(slotID);

	return msg.toString();
}

const BehaviorTreeSlot& TreeSocket::getSlotID() const {
	return slotID;
}