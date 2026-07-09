#include "RemoveDefenseSuiCallback.h"
#include "server/zone/objects/player/sui/messagebox/SuiMessageBox.h"
#include "server/zone/objects/creature/CreatureObject.h"
#include "server/zone/Zone.h"

RemoveDefenseSuiCallback::RemoveDefenseSuiCallback(ZoneServer* server, uint64 deedID) : SuiCallback(server) {
	deed = deedID;
}

void RemoveDefenseSuiCallback::run(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args) {
	bool cancelPressed = (eventIndex == 1);

	if (cancelPressed || !suiBox->isMessageBox() || player == nullptr)
		return;

	ManagedReference<SceneObject*> obj = suiBox->getUsingObject().get();

	if (obj == nullptr || !obj->isBuildingObject())
		return;

	ManagedReference<BuildingObject*> building = cast<BuildingObject*>(obj.get());

	GCWManager* gcwMan = player->getZone()->getGCWManager();

	if (gcwMan == nullptr)
		return;

	gcwMan->removeDefense(building, player, deed);
}