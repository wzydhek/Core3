#include "VendorZoneComponent.h"

void VendorZoneComponent::notifyPositionUpdate(SceneObject* sceneObject, TreeEntry* entry) const {
	ManagedReference<SceneObject*> target = cast<SceneObject*>(entry);

	if (target == nullptr || !target->isPlayerCreature()) {
		return;
	}

	VendorDataComponent* data = cast<VendorDataComponent*>(sceneObject->getDataObjectComponent()->get());

	if (data == nullptr || !data->isAdBarkingEnabled())
		return;

	float distanceSq = target->getWorldPosition().squaredDistanceTo2d(sceneObject->getWorldPosition());
	float checkSq = VendorDataComponent::BARKRANGE * VendorDataComponent::BARKRANGE;

	if (distanceSq < checkSq) {
		if (data->canBark()) {
			data->performVendorBark(target);
		} else {
			data->addBarkTarget(target->getObjectID());
		}
	} else if (data->hasBarkTarget(target->getObjectID())) {
		data->removeBarkTarget(target->getObjectID());
	}
}