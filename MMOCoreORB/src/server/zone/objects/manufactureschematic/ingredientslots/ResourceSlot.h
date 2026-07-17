/*
 				Copyright <SWGEmu>
		See file COPYING for copying conditions. */

#pragma once

#include "IngredientSlot.h"
#include "server/zone/objects/resource/ResourceSpawn.h"
#include "server/zone/objects/resource/ResourceContainer.h"
#include "server/zone/objects/tangible/TangibleObject.h"

namespace server {
namespace zone {
namespace objects {
namespace manufactureschematic {
namespace ingredientslots {

class ResourceSlot: public IngredientSlot {

	int quantity;
	VectorMap<ManagedReference<SceneObject*>, int> parents;
	ManagedReference<ResourceSpawn*> currentSpawn;

public:
	ResourceSlot();

	ResourceSlot(const ResourceSlot& slot);

	~ResourceSlot();

	Object* clone();

	bool add(CreatureObject* player, SceneObject* satchel, ManagedReference<TangibleObject*> tano);

	bool returnToParents(CreatureObject* player);

	int getSlotQuantity();

	bool isFull();

	bool isEmpty();

	bool isResourceSlot();

	ResourceSpawn* getCurrentSpawn();

	SceneObject* getFactoryIngredient();

	Vector<uint64> getOIDVector();

	Vector<int> getQuantityVector();

};

} // namespace ingredientslots
} // namespace manufactureschematic
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::manufactureschematic::ingredientslots;
