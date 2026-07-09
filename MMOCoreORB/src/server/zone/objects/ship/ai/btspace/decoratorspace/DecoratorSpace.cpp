#include "DecoratorSpace.h"

DecoratorSpace::DecoratorSpace(const String& className, const uint32 id, const LuaObject& args) : BehaviorSpace(className, id, args) {
}

DecoratorSpace::DecoratorSpace(const DecoratorSpace& b) : BehaviorSpace(b) {
	child = b.child;
}

DecoratorSpace& DecoratorSpace::operator=(const DecoratorSpace& b) {
	if (this == &b)
		return *this;

	BehaviorSpace::operator=(b);
	child = b.child;

	return *this;
}

DecoratorSpace::~DecoratorSpace() {
}

bool DecoratorSpace::isDecoratorSpace() const {
	return true;
}

bool DecoratorSpace::hasChild(BehaviorSpace* c) const {
	return child == c;
}

BehaviorSpace* DecoratorSpace::getChild(uint32 cID) const {
	if (child->getID() == cID)
		return child;

	return NULL;
}

Vector<const BehaviorSpace*> DecoratorSpace::getRecursiveChildList() const {
	Vector<const BehaviorSpace*> retVal;
	retVal.add(this);

	retVal.addAll(child->getRecursiveChildList());

	return retVal;
}

void DecoratorSpace::setChild(Reference<BehaviorSpace*> newChild) {
	assert(newChild != this);

	child = newChild;
}

String DecoratorSpace::print() const {
	StringBuffer stream;
	stream << BehaviorSpace::print() << "[";
	if (child != nullptr)
		stream << child->print();
	stream << "]";
	return stream.toString();
}

bool DecoratorSpace::checkConditions(ShipAiAgent* agent) const {
	if (child == nullptr)
		return false;

	if (!BehaviorSpace::checkConditions(agent)) {
		return true;
	}

	return true;
}

BehaviorSpace::Status DecoratorSpace::doAction(ShipAiAgent* agent) const {
#ifdef DEBUG_SHIP_AI
	if (agent->peekBlackboard("aiDebug") && agent->readBlackboard("aiDebug") == true) {
		StringBuffer msg;
		msg << "0x" << hex << id << " " << print().toCharArray();

		agent->info(true) << agent->getDisplayedName() << " ID: " << agent->getObjectID() << " - " << msg.toString();
	}
#endif // DEBUG_SHIP_AI

	if (!checkConditions(agent)) {
		return INVALID;
	}

	if (!agent->isRunningBehavior(id))
		this->start(agent);
	else
		agent->popRunningChain();

	BehaviorSpace::Status result = this->execute(agent);

#ifdef DEBUG_SHIP_AI
	if (agent->peekBlackboard("aiDebug") && agent->readBlackboard("aiDebug") == true) {
		StringBuffer msg;

		msg << "0x" << hex << id << " " << print() << " result: " << result;
		agent->info(true) << agent->getDisplayedName() << " ID: " << agent->getObjectID() << " - " << msg.toString();
	}
#endif // DEBUG_SHIP_AI

	if (result == RUNNING)
		agent->addRunningID(id);
	else
		this->end(agent);

	return result;
}