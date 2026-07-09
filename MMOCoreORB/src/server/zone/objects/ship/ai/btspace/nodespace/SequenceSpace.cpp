/*
 * SequenceSpace.cpp
 */

#include "SequenceSpace.h"
#include "server/zone/objects/ship/ai/ShipAiAgent.h"

using namespace server::zone::objects::ship::ai::btspace;

SequenceSpace::SequenceSpace(const String& className, const uint32 id, const LuaObject& args) : CompositeSpace(className, id, args) {
}

BehaviorSpace::Status SequenceSpace::execute(ShipAiAgent* agent, unsigned int startIdx) const {
	// loop through children and return FAILURE on first one that failed
	// as always, return RUNNING if any child returns RUNNING
	for (; startIdx < children.size(); ++startIdx) {
		BehaviorSpace* currentChild = children.get(startIdx);
		assert(currentChild != nullptr);

		BehaviorSpace::Status result = currentChild->doAction(agent);

		if (result == SUCCESS)
			continue;

		return result;
	}

	// We made it all the way through the list without a failure
	return SUCCESS;
}

ParallelSequenceSpace::ParallelSequenceSpace(const String& className, const uint32 id, const LuaObject& args) : CompositeSpace(className, id, args) {
}

BehaviorSpace::Status ParallelSequenceSpace::execute(ShipAiAgent* agent, unsigned int startIdx) const {
	// loop through ALL children and return failure if any fail
	BehaviorSpace::Status finalResult = SUCCESS;

	for (; startIdx < children.size(); ++startIdx) {
		BehaviorSpace* currentChild = children.get(startIdx);
		assert(currentChild != nullptr);

		BehaviorSpace::Status result = currentChild->doAction(agent);

		if (result == RUNNING)
			return RUNNING;

		if (result == FAILURE)
			finalResult = FAILURE;
	}

	return finalResult;
}

RandomSequenceSpace::RandomSequenceSpace(const String& className, const uint32 id, const LuaObject& args) : CompositeSpace(className, id, args) {
}

BehaviorSpace::Status RandomSequenceSpace::execute(ShipAiAgent* agent, unsigned int startIdx) const {
	Vector<Reference<BehaviorSpace*>> ranChildren = shuffleChildren();

	for (int i = 0; i < ranChildren.size(); ++i) {
		BehaviorSpace* currentChild = ranChildren.get(i);

		assert(currentChild != nullptr);

		BehaviorSpace::Status result = currentChild->doAction(agent);

		if (result == SUCCESS)
			continue;

		return result;
	}

	return SUCCESS;
}
