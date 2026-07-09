
#pragma once

#include "engine/engine.h"
#include "server/zone/managers/resource/ResourceManager.h"
#include "server/zone/objects/resource/ResourceContainer.h"
#include "server/zone/objects/scene/SceneObject.h"
#include "server/zone/objects/tangible/TangibleObject.h"
#include "server/zone/objects/creature/CreatureObject.h"
#include "server/zone/objects/tangible/tool/recycle/RecycleTool.h"
#include "server/zone/objects/transaction/TransactionLog.h"
#include "server/zone/objects/creature/commands/TransferItemMiscCommand.h"

class RecycleResourceTask : public Task {
private:
	ManagedReference<RecycleTool*> recycler;
	ManagedReference<TangibleObject*> insertedItem;
	ManagedReference<ResourceSpawn*> resource;
	ManagedReference<CreatureObject*> player;
	ManagedReference<SceneObject*> inventory;
	int resourceRecycleType;

public:
	RecycleResourceTask(RecycleTool* reco, TangibleObject* tano);

	void run();

	void removeFromRecycler(const String& reason);
};
