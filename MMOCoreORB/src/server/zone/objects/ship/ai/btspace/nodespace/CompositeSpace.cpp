/*
 * CompositeSpace.cpp
 */

#include "server/zone/objects/ship/ai/btspace/nodespace/CompositeSpace.h"
#include "server/zone/objects/ship/ai/ShipAiAgent.h"

using namespace server::zone::objects::ship::ai::btspace;

CompositeSpace::CompositeSpace(const String& className, const uint32 id, const LuaObject& args) : BehaviorSpace(className, id, args) {
}

CompositeSpace::CompositeSpace(const CompositeSpace& b) : BehaviorSpace(b), children(b.children) {
}

CompositeSpace& CompositeSpace::operator=(const CompositeSpace& b) {
	if (this == &b)
		return *this;

	BehaviorSpace::operator=(b);
	children = b.children;

	return *this;
}

CompositeSpace::~CompositeSpace() {
}

bool CompositeSpace::isCompositeSpace() const {
	return true;
}

bool CompositeSpace::hasChild(BehaviorSpace* c) const {
	for (int idx = 0; idx < children.size(); ++idx)
		if (children.get(idx) == c)
			return true;

	return false;
}

BehaviorSpace* CompositeSpace::getChild(uint32 cID) const {
	for (int idx = 0; idx < children.size(); ++idx)
		if (children.get(idx)->getID() == cID)
			return children.get(idx);

	return NULL;
}

Vector<const BehaviorSpace*> CompositeSpace::getRecursiveChildList() const {
	Vector<const BehaviorSpace*> retVal;
	retVal.add(this);

	for (int idx = 0; idx < children.size(); ++idx) {
		retVal.addAll(children.get(idx)->getRecursiveChildList());
	}

	return retVal;
}

void CompositeSpace::addChild(Reference<BehaviorSpace*> child) {
	assert(child != this);

	children.add(child);
}

bool CompositeSpace::checkConditions(ShipAiAgent* agent) const {
	if (children.size() <= 0)
		return false;

	if (!BehaviorSpace::checkConditions(agent)) {
		return true;
	}

	return true;
}

BehaviorSpace::Status CompositeSpace::doAction(ShipAiAgent* agent) const {
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

	// Step 1:  check if this behavior is in the running chain
	//          if it isn't, then call start(), but if it is,
	//          then we need to assume all previous children
	//          resulted in whatever status that would cause
	//          this behavior to execute (ie, if this is a
	//          selector, then all previous were fails and if
	//          this is a sequence, all previous were
	//          successes) and continue execution in order
	unsigned int currentIdx = 0;

	if (!agent->isRunningBehavior(id))
		this->start(agent);
	else { // we need to find the child that is running and start from there
		agent->popRunningChain();

		BehaviorSpace* currentChild = nullptr;

		for (; currentIdx < children.size(); ++currentIdx) {
			currentChild = children.get(currentIdx);
			assert(currentChild != nullptr);

			if (currentChild->getID() == agent->peekRunningChain())
				break;
		}

		if (currentIdx >= children.size()) {
			// this shouldn't happen, but in case we can't find the running
			// child, clear the chain (it's already mangled) and run as if
			// there was no running chain
			agent->clearRunningChain();
			currentChild = children.get(0);
		}
	}

	// Step 2:  evaluate the action result. The method to do this will differ
	//			depending on the type of composite this is, so this will just
	//			call the abstract method to do it.
	BehaviorSpace::Status result = this->execute(agent, currentIdx);

#ifdef DEBUG_SHIP_AI
	if (agent->peekBlackboard("aiDebug") && agent->readBlackboard("aiDebug") == true) {
		StringBuffer msg;
		msg << "0x" << hex << id << " " << print() << "result: " << result;

		agent->info(true) << agent->getDisplayedName() << " ID: " << agent->getObjectID() << " - " << msg.toString();
	}
#endif // DEBUG_SHIP_AI

	// Step 3:  if the child result is running, then set this
	//          state to running and push the behavior to the
	//          front of the AI's running chain
	if (result == RUNNING)
		agent->addRunningID(id);
	else
		this->end(agent);

	// Step 4:  return the result
	return result;
}

String CompositeSpace::print() const {
	StringBuffer stream;
	stream << BehaviorSpace::print() << "[";

	for (int i = 0; i < children.size(); i++) {
		stream << children.get(i)->print() << " ";
	}

	stream << "]";

	return stream.toString();
}

Vector<Reference<BehaviorSpace*>> CompositeSpace::shuffleChildren() const {
	Vector<Reference<BehaviorSpace*>> ran = children;

	for (int i = 0; i < ran.size(); ++i) {
		int index = (int)System::random(ran.size() - 1 - i) + i;

		Reference<BehaviorSpace*> temp = ran.set(i, ran.get(index));

		ran.set(index, temp);
	}

	return ran;
}