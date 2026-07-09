#include "FindLostItemsSuiCallback.h"

FindLostItemsSuiCallback::FindLostItemsSuiCallback(ZoneServer* serv) : SuiCallback(serv) {
}

void FindLostItemsSuiCallback::run(CreatureObject* creature, SuiBox* sui, uint32 eventIndex, Vector<UnicodeString>* args) {
	bool cancelPressed = (eventIndex == 1);

	if (!sui->isMessageBox() || cancelPressed)
		return;

	ManagedReference<SceneObject*> obj = sui->getUsingObject().get();

	if (obj == nullptr || !obj->isBuildingObject())
		return;

	BuildingObject* building = cast<BuildingObject*>(obj.get());

	if (building->getZone() == nullptr)
		return;

	StructureManager::instance()->moveFirstItemTo(creature, building);
}