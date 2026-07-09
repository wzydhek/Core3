#pragma once

#include "server/zone/objects/ship/ai/btspace/BehaviorSpace.h"
#include "server/zone/objects/ship/ai/ShipAiAgent.h"

namespace server {
namespace zone {
namespace objects {
namespace ship {
namespace ai {
namespace btspace {
namespace decoratorspace {

class DecoratorSpace : public BehaviorSpace {
protected:
	Reference<BehaviorSpace*> child;

public:
	DecoratorSpace(const String& className, const uint32 id, const LuaObject& args);

	DecoratorSpace(const DecoratorSpace& b);

	DecoratorSpace& operator=(const DecoratorSpace& b);

	virtual ~DecoratorSpace();

	bool isDecoratorSpace() const;

	bool hasChild(BehaviorSpace* c) const;

	BehaviorSpace* getChild(uint32 cID) const;

	Vector<const BehaviorSpace*> getRecursiveChildList() const;

	virtual void setChild(Reference<BehaviorSpace*> newChild);

	String print() const;

	virtual bool checkConditions(ShipAiAgent* agent) const;

	BehaviorSpace::Status doAction(ShipAiAgent* agent) const;
};

} // namespace decoratorspace
} // namespace btspace
} // namespace ai
} // namespace ship
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::ship::ai::btspace::decoratorspace;