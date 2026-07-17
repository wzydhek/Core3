/*
 				Copyright <SWGEmu>
		See file COPYING for copying conditions. */

#pragma once

#include "IngredientSlot.h"
#include "server/zone/managers/object/ObjectManager.h"
#include "server/zone/objects/factorycrate/FactoryCrate.h"

// #define DEBUG_COMPONENT_SLOT

namespace server {
namespace zone {
namespace objects {
namespace manufactureschematic {
namespace ingredientslots {

class ComponentSlot: public IngredientSlot {
	/// Indexed by <object, parent>
	Vector<ManagedReference<TangibleObject*> > contents;

public:
	ComponentSlot();

	ComponentSlot(const ComponentSlot& slot);

	~ComponentSlot();

	Object* clone();

	bool add(CreatureObject* player, SceneObject* satchel, ManagedReference<TangibleObject*> incomingTano);

	bool returnToParents(CreatureObject* player);

	int getSlotQuantity();

	bool isFull();

	bool isEmpty();

	TangibleObject* getPrototype();

	SceneObject* getFactoryIngredient();

	bool isComponentSlot();

	Vector<uint64> getOIDVector();

	// We add 1 for each item in the slot
	// NOT the quantity of each item, it's a vector
	// of 1's that equals how many items are in the slot
	Vector<int> getQuantityVector();
};

} // namespace ingredientslots
} // namespace manufactureschematic
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::manufactureschematic::ingredientslots;
