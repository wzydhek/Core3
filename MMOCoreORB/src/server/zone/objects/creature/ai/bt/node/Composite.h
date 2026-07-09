/*
 * Composite
 *
 *  Created on: Aug 24, 2013
 *      Author: swgemu
 */

#pragma once

#include "server/zone/objects/creature/ai/bt/Behavior.h"

namespace server {
namespace zone {
namespace objects {
namespace creature {
namespace ai {
namespace bt {
namespace node {

class Composite : public Behavior {
protected:
	Vector<Reference<Behavior*> > children;

	Vector<Reference<Behavior*>> shuffleChildren() const;

public:
	Composite(const String& className, const uint32 id, const LuaObject& args);

	Composite(const Composite& b);

	Composite& operator=(const Composite& b);

	virtual ~Composite();

	bool isComposite() const;

	bool hasChild(Behavior* c) const;

	Behavior* getChild(uint32 cID) const;

	Vector<const Behavior*> getRecursiveChildList() const;

	virtual void addChild(Reference<Behavior*> child);

	String print() const;

	virtual bool checkConditions(AiAgent* agent) const;

	Behavior::Status doAction(AiAgent* agent) const;
};

}
}
}
}
}
}
}

using namespace server::zone::objects::creature::ai::bt::node;
