#pragma once

#include "server/zone/objects/creature/ai/bt/Behavior.h"

namespace server {
namespace zone {
namespace objects {
namespace creature {
namespace ai {
namespace bt {
namespace decorator {

class Decorator : public Behavior {
protected:
	Reference<Behavior*> child;

public:
	Decorator(const String& className, const uint32 id, const LuaObject& args);

	Decorator(const Decorator& b);

	Decorator& operator=(const Decorator& b);

	virtual ~Decorator();

	bool isDecorator() const;

	bool hasChild(Behavior* c) const;

	Behavior* getChild(uint32 cID) const;

	Vector<const Behavior*> getRecursiveChildList() const;

	virtual void setChild(Reference<Behavior*> newChild);

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

using namespace server::zone::objects::creature::ai::bt::decorator;
