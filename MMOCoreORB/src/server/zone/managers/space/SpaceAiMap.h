/*
 * SpaceAiMap.h
 */

#pragma once

#include "server/ServerCore.h"
#include "system/util/VectorMap.h"

// Space AI
#include "server/zone/objects/ship/ai/btspace/BehaviorSpace.h"
#include "server/zone/objects/ship/ai/btspace/BehaviorTreeSlotSpace.h"
#include "templates/params/ship/ShipFlag.h"

// include all behaviors we want to register
#include "server/zone/objects/ship/ai/btspace/TreeSocketSpace.h"
#include "server/zone/objects/ship/ai/btspace/nodespace/SelectorSpace.h"
#include "server/zone/objects/ship/ai/btspace/nodespace/SequenceSpace.h"
#include "server/zone/objects/ship/ai/btspace/leafspace/ChecksSpace.h"
#include "server/zone/objects/ship/ai/btspace/leafspace/FollowActionsSpace.h"
#include "server/zone/objects/ship/ai/btspace/leafspace/SimpleActionsSpace.h"
#include "server/zone/objects/ship/ai/btspace/decoratorspace/AlwaysFailSpace.h"
#include "server/zone/objects/ship/ai/btspace/decoratorspace/AlwaysSucceedSpace.h"
#include "server/zone/objects/ship/ai/btspace/decoratorspace/IfSpace.h"
#include "server/zone/objects/ship/ai/btspace/decoratorspace/NotSpace.h"
#include "server/zone/objects/ship/ai/btspace/decoratorspace/UntilFailureSpace.h"
#include "server/zone/objects/ship/ai/btspace/decoratorspace/UntilSuccessSpace.h"
#include "server/zone/objects/ship/ai/btspace/decoratorspace/LookForTargetSpace.h"

#define _REGISTERSPACEBASE(name) factory.reg(#name, new SpaceBehaviorCreator<name>)
#define _REGISTERSPACENODE(name) factory.reg(#name, new SpaceBehaviorCreator<nodespace::name>)
#define _REGISTERSPACELEAF(name) factory.reg(#name, new SpaceBehaviorCreator<leafspace::name>)
#define _REGISTERSPACEDECO(name) factory.reg(#name, new SpaceBehaviorCreator<decoratorspace::name>)

namespace server {
namespace zone {
namespace managers {
namespace space {

class SpaceBehaviorCreatorHelper {
public:
	virtual ~SpaceBehaviorCreatorHelper() {
	}
	virtual BehaviorSpace* create(const String&, const uint32, const LuaObject&) const = 0;
};

template <typename T>
class SpaceBehaviorCreator : public SpaceBehaviorCreatorHelper {
public:
	BehaviorSpace* create(const String& name, const uint32 id, const LuaObject& args) const {
		return new T(name, id, args);
	}
};

class SpaceBehaviorFactory {
public:
	~SpaceBehaviorFactory();

	void reg(const String& key, const SpaceBehaviorCreatorHelper* fn);

	BehaviorSpace* create(const String& key, const uint32 id, const LuaObject& args);

private:
	HashTable<String, const SpaceBehaviorCreatorHelper*> fnMap;
};

class SpaceAiMap : public Singleton<SpaceAiMap>, public Logger, public Object {
public:
	// <template name, root behavior>
	HashTable<String, Reference<BehaviorSpace*>> spaceAiMap;
	// <ai bitmask, <treeID, root behavior> >
	VectorMap<uint32, VectorMap<BehaviorTreeSlotSpace, Reference<BehaviorSpace*>>> bitmaskMap;
	VectorMap<uint64, VectorMap<BehaviorTreeSlotSpace, Reference<BehaviorSpace*>>> customMap;

	AtomicInteger countExceptions;
	AtomicInteger activeBehaviorEvents;
	AtomicInteger scheduledBehaviorEvents;
	AtomicInteger behaviorsWithFollowObject;
	AtomicInteger behaviorsRetreating;
	AtomicInteger activeRecoveryEvents;

	Mutex guard;

	SpaceAiMap();

	~SpaceAiMap();

	void initialize();

	void loadTemplates();

	int getTemplateSize();

	// put the root node of a btree into this map
	void putTemplate(const String& name, Reference<BehaviorSpace*> ait);

	// returns the root node of a behavior tree
	BehaviorSpace* getTemplate(const String& name);

	// returns the root node of a behavior tree associated with the tree type (treeID)
	BehaviorSpace* getTemplate(uint32 bitMask, BehaviorTreeSlotSpace treeID, uint64 customMapName = 0);

	BehaviorSpace* createBehavior(const String& name, const uint32 id, const LuaObject& args);

	const JSONSerializationType getStatsAsJSON() const;

private:
	static const bool DEBUG_MODE = false;
	SpaceBehaviorFactory factory;

	void registerBehaviors();

	void putBitmask(Lua* lua, String key);

	void loadCustomMap(Lua* lua);

	static int includeFile(lua_State* L);

	static int addSpaceAiTemplate(lua_State* L);
};

} // namespace space
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::space;
