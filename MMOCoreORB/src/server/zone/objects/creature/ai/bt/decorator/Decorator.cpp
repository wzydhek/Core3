#include "Decorator.h"
#include "server/zone/objects/creature/ai/AiAgent.h"

Decorator::Decorator(const String& className, const uint32 id, const LuaObject& args) : Behavior(className, id, args) {
}

Decorator::Decorator(const Decorator& b) : Behavior(b) {
	child = b.child;
}

Decorator& Decorator::operator=(const Decorator& b) {
	if (this == &b)
		return *this;

	Behavior::operator=(b);
	child = b.child;

	return *this;
}

Decorator::~Decorator() {
}

bool Decorator::isDecorator() const {
	return true;
}

bool Decorator::hasChild(Behavior* c) const {
	return child == c;
}

Behavior* Decorator::getChild(uint32 cID) const {
	if (child->getID() == cID)
		return child;

	return NULL;
}

Vector<const Behavior*> Decorator::getRecursiveChildList() const {
	Vector<const Behavior*> retVal;
	retVal.add(this);

	retVal.addAll(child->getRecursiveChildList());

	return retVal;
}

void Decorator::setChild(Reference<Behavior*> newChild) {
	assert(child != this);

	child = newChild;
}

String Decorator::print() const {
	StringBuffer stream;
	stream << Behavior::print() << "[";
	if (child != nullptr)
		stream << child->print();
	stream << "]";
	return stream.toString();
}

bool Decorator::checkConditions(AiAgent* agent) const {
	if (child == nullptr)
		return false;

	if (!Behavior::checkConditions(agent)) {
		return true;
	}

	return true;
}

Behavior::Status Decorator::doAction(AiAgent* agent) const {
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

	if (!agent->isRunningBehavior(id))
		this->start(agent);
	else
		agent->popRunningChain();

	Behavior::Status result = this->execute(agent);

#ifdef DEBUG_AI
	if (agent->peekBlackboard("aiDebug") && agent->readBlackboard("aiDebug") == true) {
		StringBuffer msg;

		msg << "0x" << hex << id << " " << print() << " result: " << result;
		agent->info(msg.toString(), true);
	}
#endif // DEBUG_AI

	if (result == RUNNING)
		agent->addRunningID(id);
	else
		this->end(agent);

	return result;
}