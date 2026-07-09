/*
 * CompositeSpace.h
 */

#pragma once

#include "server/zone/objects/ship/ai/btspace/BehaviorSpace.h"

namespace server {
namespace zone {
namespace objects {
namespace ship {
namespace ai {
namespace btspace {
namespace nodespace {

class CompositeSpace : public BehaviorSpace {
protected:
	Vector<Reference<BehaviorSpace*>> children;

	Vector<Reference<BehaviorSpace*>> shuffleChildren() const;

public:
	CompositeSpace(const String& className, const uint32 id, const LuaObject& args);

	CompositeSpace(const CompositeSpace& b);

	CompositeSpace& operator=(const CompositeSpace& b);

	virtual ~CompositeSpace();

	bool isCompositeSpace() const;

	bool hasChild(BehaviorSpace* c) const;

	BehaviorSpace* getChild(uint32 cID) const;

	Vector<const BehaviorSpace*> getRecursiveChildList() const;

	virtual void addChild(Reference<BehaviorSpace*> child);

	String print() const;

	virtual bool checkConditions(ShipAiAgent* agent) const;

	BehaviorSpace::Status doAction(ShipAiAgent* agent) const;
};

} // namespace nodespace
} // namespace btspace
} // namespace ai
} // namespace ship
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::ship::ai::btspace::nodespace;
