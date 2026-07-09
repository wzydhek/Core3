#include "DataStorageUnitAttributeListComponent.h"

void DataStorageUnitAttributeListComponent::fillAttributeList(AttributeListMessage* alm, CreatureObject* player, SceneObject* sceneObject) const {
	if (!sceneObject->isTangibleObject())
		return;

	ManagedReference<TangibleObject*> tano = cast<TangibleObject*>(sceneObject);

	if (!player->isPlayerCreature())
		return;

	DataObjectComponent* data = tano->getDataObjectComponent()->get();
	if (data == nullptr || !data->isDataStorageUnitData())
		return;

	DataStorageUnitDataComponent* dsuData = cast<DataStorageUnitDataComponent*>(data);
	if (dsuData == nullptr)
		return;

	// ID is an integer from 1 to 12
	String title = "@theme_park/book_text:title_" + String::valueOf(dsuData->getId());
	alm->insertAttribute("contents", title);
}