#include "RecycleToolContainerComponent.h"

int RecycleToolContainerComponent::notifyObjectInserted(SceneObject* sceneObject, SceneObject* object) const {
	RecycleTool* recycler = cast<RecycleTool*>(sceneObject);

	TangibleObject* tano = cast<TangibleObject*>(object);

	if (recycler != nullptr && tano != nullptr) {
		RecycleResourceTask* task = new RecycleResourceTask(recycler, tano);

		if (task != nullptr) {
			task->run();
		}
	}

	return ContainerComponent::notifyObjectInserted(sceneObject, object);
}

bool RecycleToolContainerComponent::removeObject(SceneObject* sceneObject, SceneObject* object, SceneObject* destination, bool notifyClient, bool nullifyParent) const {
	return ContainerComponent::removeObject(sceneObject, object, destination, notifyClient, nullifyParent);
}

int RecycleToolContainerComponent::canAddObject(SceneObject* sceneObject, SceneObject* object, int containmentType, String& errorDescription) const {
	ManagedReference<SceneObject*> parent = sceneObject->getParentRecursively(SceneObjectType::PLAYERCREATURE);

	if (parent == nullptr)
		return TransferErrorCode::MUSTBEINPLAYERINVENTORY;

	if (parent != object->getParentRecursively(SceneObjectType::PLAYERCREATURE))
		return TransferErrorCode::MUSTBEINPLAYERINVENTORY;

	int containerObjects = parent->getSlottedObject("inventory")->getContainerObjectsSize();

	if (containerObjects >= parent->getSlottedObject("inventory")->getContainerVolumeLimit()) {
		errorDescription = "@error_message:inv_full"; // Your inventory is full.

		return TransferErrorCode::CONTAINERFULL;
	}

	return ContainerComponent::canAddObject(sceneObject, object, containmentType, errorDescription);
}