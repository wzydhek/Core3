/*
 * Composite.cpp
 *
 *  Created on: Jun 11, 2014
 *      Author: swgemu
 */

#include "server/zone/objects/creature/ai/bt/node/Composite.h"
#include "server/zone/objects/creature/ai/AiAgent.h"

using namespace server::zone::objects::creature::ai::bt;

Composite::Composite(const String& className, const uint32 id, const LuaObject& args) : Behavior(className, id, args) {
}

Composite::Composite(const Composite& b) : Behavior(b), children(b.children) {
}

Composite& Composite::operator=(const Composite& b) {
	if (this == &b)
		return *this;

	Behavior::operator=(b);
	children = b.children;

	return *this;
}

Composite::~Composite() {
}

bool Composite::isComposite() const {
	return true;
}

bool Composite::hasChild(Behavior* c) const {
	for (int idx = 0; idx < children.size(); ++idx)
		if (children.get(idx) == c)
			return true;

	return false;
}

Behavior* Composite::getChild(uint32 cID) const {
	for (int idx = 0; idx < children.size(); ++idx)
		if (children.get(idx)->getID() == cID)
			return children.get(idx);

	return NULL;
}

Vector<const Behavior*> Composite::getRecursiveChildList() const {
	Vector<const Behavior*> retVal;
	retVal.add(this);

	for (int idx = 0; idx < children.size(); ++idx) {
		retVal.addAll(children.get(idx)->getRecursiveChildList());
	}

	return retVal;
}

void Composite::addChild(Reference<Behavior*> child) {
	assert(child != this);

	children.add(child);
}

Behavior::Status Composite::doAction(AiAgent* agent) const {
#ifdef DEBUG_AI
	if (agent->peekBlackboard("aiDebug") && agent->readBlackboard("aiDebug") == true) {
		StringBuffer msg;
		msg << "0x" << hex << id << " " << print().toCharArray();

		agent->info(msg.toString(), true);
	}
#endif // DEBUG_AI

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

		Behavior* currentChild = nullptr;
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
	Behavior::Status result = this->execute(agent, currentIdx);
#ifdef DEBUG_AI
	if (agent->peekBlackboard("aiDebug") && agent->readBlackboard("aiDebug") == true) {
		StringBuffer msg;
		msg << "0x" << hex << id << " " << print() << "result: " << result;

		agent->info(msg.toString(), true);
	}
#endif // DEBUG_AI

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

String Composite::print() const {
	StringBuffer stream;
	stream << Behavior::print() << "[";
	for (int i = 0; i < children.size(); i++) {
		stream << children.get(i)->print() << " ";
	}
	stream << "]";
	return stream.toString();
}

bool Composite::checkConditions(AiAgent* agent) const {
	if (children.size() <= 0)
		return false;

	if (!Behavior::checkConditions(agent)) {
		return true;
	}

	return true;
}

Vector<Reference<Behavior*>> Composite::shuffleChildren() const {
	Vector<Reference<Behavior*>> ran = children;

	for (int i = 0; i < ran.size(); ++i) {
		int index = (int)System::random(ran.size() - 1 - i) + i;
		Reference<Behavior*> temp = ran.set(i, ran.get(index));
		ran.set(index, temp);
	}

	return ran;
}