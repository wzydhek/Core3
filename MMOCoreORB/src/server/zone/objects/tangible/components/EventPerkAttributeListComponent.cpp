#include "EventPerkAttributeListComponent.h"

void EventPerkAttributeListComponent::fillAttributeList(AttributeListMessage* alm, CreatureObject* player, SceneObject* sceneObject) const {
	if (player == nullptr || sceneObject == nullptr || !sceneObject->isTangibleObject())
		return;

	// Fill from parent
	AttributeListComponent::fillAttributeList(alm, player, sceneObject);

	EventPerkDataComponent* data = cast<EventPerkDataComponent*>(sceneObject->getDataObjectComponent()->get());

	if (data == nullptr) {
		error() << "Event Perk EventPerkDataComponent is nullptr, destroying EventPerk ID: " << sceneObject->getObjectID();

		Locker lock(sceneObject);
		sceneObject->destroyObjectFromWorld(true);
		sceneObject->destroyObjectFromDatabase(true);

		return;
	}

	EventPerkDeed* deed = data->getDeed();

	if (deed == nullptr) {
		error() << "Event Perk Deed is nullptr, destroying EventPerk ID: " << sceneObject->getObjectID();

		Locker lock(sceneObject);
		sceneObject->destroyObjectFromWorld(true);
		sceneObject->destroyObjectFromDatabase(true);

		return;
	}

	ManagedReference<CreatureObject*> owner = deed->getOwner().get();
	if (owner != nullptr) {
		alm->insertAttribute("owner", owner->getFirstName());
	}
}