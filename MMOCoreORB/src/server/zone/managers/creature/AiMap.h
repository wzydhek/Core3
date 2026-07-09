/*
 * AiMap.h
 *
 *  Created on: May 17, 2012
 *      Author: da
 */

#pragma once

#include "server/ServerCore.h"
#include "system/util/VectorMap.h"
#include "server/zone/objects/creature/ai/bt/Behavior.h"
#include "server/zone/objects/creature/ai/bt/BehaviorTreeSlot.h"
#include "templates/params/creature/ObjectFlag.h"
#include "templates/params/creature/CreaturePosture.h"
#include "templates/params/creature/CreatureState.h"
#include "server/zone/managers/creature/PetManager.h"

// include all behaviors we want to register
#include "server/zone/objects/creature/ai/bt/TreeSocket.h"
#include "server/zone/objects/creature/ai/bt/node/Selector.h"
#include "server/zone/objects/creature/ai/bt/node/Sequence.h"
#include "server/zone/objects/creature/ai/bt/leaf/Checks.h"
#include "server/zone/objects/creature/ai/bt/leaf/FollowActions.h"
#include "server/zone/objects/creature/ai/bt/leaf/SimpleActions.h"
#include "server/zone/objects/creature/ai/bt/decorator/AlwaysFail.h"
#include "server/zone/objects/creature/ai/bt/decorator/AlwaysSucceed.h"
#include "server/zone/objects/creature/ai/bt/decorator/If.h"
#include "server/zone/objects/creature/ai/bt/decorator/Not.h"
#include "server/zone/objects/creature/ai/bt/decorator/UntilFailure.h"
#include "server/zone/objects/creature/ai/bt/decorator/UntilSuccess.h"
#include "server/zone/objects/creature/ai/bt/decorator/LookForTarget.h"
#include "server/zone/objects/creature/ai/bt/decorator/LookForPlayer.h"
#include "server/zone/objects/creature/ai/bt/decorator/LookForAllies.h"

#define _REGISTERBASE(name) factory.reg(#name, new BehaviorCreator<name>)
#define _REGISTERNODE(name) factory.reg(#name, new BehaviorCreator<node::name>)
#define _REGISTERLEAF(name) factory.reg(#name, new BehaviorCreator<leaf::name>)
#define _REGISTERDECO(name) factory.reg(#name, new BehaviorCreator<decorator::name>)

class BehaviorCreatorHelper {
public:
	virtual ~BehaviorCreatorHelper() {}
	virtual Behavior* create(const String&, const uint32, const LuaObject&) const = 0;
};

template <typename T>
class BehaviorCreator : public BehaviorCreatorHelper {
public:
	Behavior* create(const String& name, const uint32 id, const LuaObject& args) const {
		return new T(name, id, args);
	}
};

class BehaviorFactory {
public:
	~BehaviorFactory();

	void reg(const String& key, const BehaviorCreatorHelper* fn);

	Behavior* create(const String& key, const uint32 id, const LuaObject& args);

private:
	HashTable<String, const BehaviorCreatorHelper*> fnMap;
};

class AiMap : public Singleton<AiMap>, public Logger, public Object {
public:
	// <template name, root behavior>
	HashTable<String, Reference<Behavior*> > aiMap;
	// <ai bitmask, <treeID, root behavior> >
	VectorMap<uint32, VectorMap<BehaviorTreeSlot, Reference<Behavior*> > > bitmaskMap;
	VectorMap<uint64, VectorMap<BehaviorTreeSlot, Reference<Behavior*> > > customMap;

	AtomicInteger countExceptions;
	AtomicInteger activeBehaviorEvents;
	AtomicInteger scheduledBehaviorEvents;
	AtomicInteger behaviorsWithFollowObject;
	AtomicInteger behaviorsRetreating;
	AtomicInteger activeRecoveryEvents;

	Mutex guard;

	AiMap();

	~AiMap();

	void initialize();

	void loadTemplates();

	int getTemplateSize();

	// put the root node of a btree into this map
	void putTemplate(const String& name, Reference<Behavior*> ait);

	// returns the root node of a behavior tree
	Behavior* getTemplate(const String& name);

	// returns the root node of a behavior tree associated with the tree type (treeID)
	Behavior* getTemplate(uint32 bitMask, BehaviorTreeSlot treeID, uint64 customMapName = 0);

	Behavior* createBehavior(const String& name, const uint32 id, const LuaObject& args);

	const JSONSerializationType getStatsAsJSON() const;

private:
	static const bool DEBUG_MODE = false;
	BehaviorFactory factory;

	void registerBehaviors();

	void putBitmask(Lua* lua, String key);

	void loadCustomMap(Lua* lua);

	static int includeFile(lua_State* L);

	static int addAiTemplate(lua_State* L);
};
