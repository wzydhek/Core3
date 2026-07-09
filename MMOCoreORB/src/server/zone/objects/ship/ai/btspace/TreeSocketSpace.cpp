#include "TreeSocketSpace.h"

TreeSocketSpace::TreeSocketSpace(const String& className, const uint32 id, const LuaObject& args) : BehaviorSpace(className, id, args), slotID(BehaviorTreeSlotSpace::NONESPACE) {
	parseArgs(args);
}

TreeSocketSpace::TreeSocketSpace(const TreeSocketSpace& b) : BehaviorSpace(b), slotID(b.slotID) {
}

TreeSocketSpace& TreeSocketSpace::operator=(const TreeSocketSpace& b) {
	if (this == &b)
		return *this;

	BehaviorSpace::operator=(b);
	slotID = b.slotID;
	return *this;
}

bool TreeSocketSpace::isSocketSpace() const {
	return true;
}

BehaviorSpace::Status TreeSocketSpace::execute(ShipAiAgent* agent, unsigned int startIdx) const {
	const BehaviorSpace* child = agent->getBehaviorTreeSpace(slotID);

	if (child == nullptr)
		return FAILURE;

	return child->doAction(agent);
}

void TreeSocketSpace::parseArgs(const LuaObject& args) {
	slotID = getArg<BehaviorTreeSlotSpace>()(args, "slot");
}

String TreeSocketSpace::print() const {
	StringBuffer msg;
	msg << className << "-" << getBehaviorTreeSlotName(slotID);

	return msg.toString();
}

const BehaviorTreeSlotSpace& TreeSocketSpace::getSlotID() const {
	return slotID;
}