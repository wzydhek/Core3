#include "ResourceSlot.h"

ResourceSlot::ResourceSlot() : IngredientSlot() {
	setLoggingName("ResourceSlot");
	quantity = 0;
	clientSlotType = 4;
	parents.setAllowDuplicateInsertPlan();
}

ResourceSlot::ResourceSlot(const ResourceSlot& slot) : Object(), IngredientSlot(slot) {
	setLoggingName("ResourceSlot");
	quantity = slot.quantity;
	parents.setAllowDuplicateInsertPlan();
	parents = slot.parents;
	currentSpawn = slot.currentSpawn;
}

ResourceSlot::~ResourceSlot() {
}

Object* ResourceSlot::clone() {
	return new ResourceSlot(*this);
}

bool ResourceSlot::add(CreatureObject* player, SceneObject* satchel, ManagedReference<TangibleObject*> tano) {
	/// Must be a resource container to proceed, and
	if (tano->isResourceContainer()) {
		ResourceContainer* incomingResource = cast<ResourceContainer*>(tano.get());

		/// Get spawn object
		ManagedReference<ResourceSpawn*> spawn = incomingResource->getSpawnObject();

		if (spawn == nullptr)
			return false;

		if (currentSpawn != nullptr && currentSpawn != spawn)
			return false;

		/// Verify the resource is the right type
		if (!incomingResource->getSpawnObject()->isType(contentType))
			return false;

		if (currentSpawn == nullptr) {
			currentSpawn = spawn;
		}

		int slotNeeds = requiredQuantity - quantity;
		int currentQuantity = 0;

		ManagedReference<SceneObject*> parent = incomingResource->getParent().get();

		if (incomingResource->getQuantity() >= slotNeeds) {
			incomingResource->setQuantity(incomingResource->getQuantity() - slotNeeds, true);
			quantity += slotNeeds;
			currentQuantity = slotNeeds;

		} else {
			quantity += incomingResource->getQuantity();
			currentQuantity = incomingResource->getQuantity();
			incomingResource->setQuantity(0, true);
		}

		VectorMapEntry<ManagedReference<SceneObject*>, int> entry(parent, currentQuantity);
		parents.add(entry);

		return true;
	}

	return false;
}

bool ResourceSlot::returnToParents(CreatureObject* player) {
	if (parents.size() == 0)
		return true;

	if (currentSpawn == nullptr) {
		warning("Spawn is null when trying to return resources");
		return false;
	}

	for (int i = 0; i < parents.size(); ++i) {
		SceneObject* parent = parents.elementAt(i).getKey();

		if (parent == nullptr)
			continue;

		bool found = false;
		// Check inventory for resource and add if existing
		for (int j = 0; j < parent->getContainerObjectsSize(); ++j) {
			ManagedReference<SceneObject*> object = parent->getContainerObject(j);

			if (object->isResourceContainer()) {
				ManagedReference<ResourceContainer*> resource = cast<ResourceContainer*>(object.get());

				if (resource->getSpawnName() == currentSpawn->getName()) {
					resource->setQuantity(resource->getQuantity() + parents.get(i));
					found = true;
					break;
				}
			}
		}

		if (!found) {
			Locker locker(currentSpawn);

			ManagedReference<ResourceContainer*> newContainer = currentSpawn->createResource(parents.get(i));

			locker.release();

			if (newContainer != nullptr && newContainer->getQuantity() > 0) {
				Locker locker(newContainer);

				if (parent->transferObject(newContainer, -1, false)) {
					parent->broadcastObject(newContainer, true);
				} else {
					error("Unable to return resource to parent, transfer failed");
					newContainer->destroyObjectFromDatabase(true);
				}
			} else {
				error("Unable to return resource to parent, nullptr container");

				if (newContainer != nullptr) {
					Locker locker(newContainer);

					newContainer->destroyObjectFromDatabase(true);
				}
			}
		}
	}

	parents.removeAll();
	currentSpawn = nullptr;
	quantity = 0;
	return true;
}

int ResourceSlot::getSlotQuantity() {
	return quantity;
}

bool ResourceSlot::isFull() {
	return quantity == requiredQuantity;
}

bool ResourceSlot::isEmpty() {
	return quantity == 0;
}

bool ResourceSlot::isResourceSlot() {
	return true;
}

ResourceSpawn* ResourceSlot::getCurrentSpawn() {
	return currentSpawn;
}

SceneObject* ResourceSlot::getFactoryIngredient() {
	return getCurrentSpawn();
}

Vector<uint64> ResourceSlot::getOIDVector() {
	Vector<uint64> oid;
	if (currentSpawn != nullptr)
		oid.add(currentSpawn->getObjectID());
	return oid;
}

Vector<int> ResourceSlot::getQuantityVector() {
	Vector<int> oid;

	oid.add(quantity);

	return oid;
}