/*
 * Sequence.cpp
 *
 *  Created on: Aug 24, 2013
 *      Author: swgemu
 */

#include "server/zone/objects/creature/ai/bt/node/Sequence.h"
#include "server/zone/objects/creature/ai/AiAgent.h"

using namespace server::zone::objects::creature::ai::bt;

Sequence::Sequence(const String& className, const uint32 id, const LuaObject& args) : Composite(className, id, args) {
}


Behavior::Status Sequence::execute(AiAgent* agent, unsigned int startIdx) const {
	// loop through children and return FAILURE on first one that failed
	// as always, return RUNNING if any child returns RUNNING
	for (; startIdx < children.size(); ++startIdx) {
		Behavior* currentChild = children.get(startIdx);
		assert(currentChild != nullptr);

		Behavior::Status result = currentChild->doAction(agent);

		if (result == SUCCESS)
			continue;

		return result;
	}

	// We made it all the way through the list without a failure
	return SUCCESS;
}

ParallelSequence::ParallelSequence(const String& className, const uint32 id, const LuaObject& args) : Composite(className, id, args) {
}

Behavior::Status ParallelSequence::execute(AiAgent* agent, unsigned int startIdx) const {
	// loop through ALL children and return failure if any fail
	Behavior::Status finalResult = SUCCESS;
	for (; startIdx < children.size(); ++startIdx) {
		Behavior* currentChild = children.get(startIdx);
		assert(currentChild != nullptr);

		Behavior::Status result = currentChild->doAction(agent);

		if (result == RUNNING)
			return RUNNING;

		if (result == FAILURE)
			finalResult = FAILURE;
	}

	return finalResult;
}

RandomSequence::RandomSequence(const String& className, const uint32 id, const LuaObject& args) : Composite(className, id, args) {
}

Behavior::Status RandomSequence::execute(AiAgent* agent, unsigned int startIdx) const {
	Vector<Reference<Behavior*> > ranChildren = shuffleChildren();
	for (int i = 0; i < ranChildren.size(); ++i) {
		Behavior* currentChild = ranChildren.get(i);
		assert(currentChild != nullptr);

		Behavior::Status result = currentChild->doAction(agent);

		if (result == SUCCESS)
			continue;

		return result;
	}

	return SUCCESS;
}
