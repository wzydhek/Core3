#include "StructurePayAccessFeeSuiCallback.h"
#include "server/zone/objects/player/sui/messagebox/SuiMessageBox.h"

StructurePayAccessFeeSuiCallback::StructurePayAccessFeeSuiCallback(ZoneServer* serv) : SuiCallback(serv) {
}

void StructurePayAccessFeeSuiCallback::run(CreatureObject* player, SuiBox* sui, uint32 eventIndex, Vector<UnicodeString>* args) {
	bool cancelPressed = (eventIndex == 1);

	if (!sui->isMessageBox() || cancelPressed)
		return;

	ManagedReference<SceneObject*> usingObject = sui->getUsingObject().get();

	if (usingObject == nullptr || !usingObject->isBuildingObject())
		return;

	BuildingObject* buildingObject = cast<BuildingObject*>(usingObject.get());

	buildingObject->payAccessFee(player);
}