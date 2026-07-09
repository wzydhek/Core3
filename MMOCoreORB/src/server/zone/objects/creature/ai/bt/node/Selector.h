/*
 * Selector.h
 *
 *  Created on: Jun 11, 2014
 *      Author: swgemu
 */

#pragma once

#include "server/zone/objects/creature/ai/bt/node/Composite.h"

namespace server {
namespace zone {
namespace objects {
namespace creature {
namespace ai {
namespace bt {
namespace node {

class Selector : public Composite {
public:
	Selector(const String& className, const uint32 id, const LuaObject& args);

	virtual Behavior::Status execute(AiAgent* agent, unsigned int startIdx = 0) const;
};

class ParallelSelector : public Composite {
public:
	ParallelSelector(const String& className, const uint32 id, const LuaObject& args);

	virtual Behavior::Status execute(AiAgent* agent, unsigned int startIdx = 0) const;
};

class RandomSelector : public Composite {
public:
	RandomSelector(const String& className, const uint32 id, const LuaObject& args);

	virtual Behavior::Status execute(AiAgent* agent, unsigned int startIdx = 0) const;
};

}
}
}
}
}
}
}

using namespace server::zone::objects::creature::ai::bt::node;
