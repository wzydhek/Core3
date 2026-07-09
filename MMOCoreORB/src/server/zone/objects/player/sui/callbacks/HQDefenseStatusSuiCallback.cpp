#include "HQDefenseStatusSuiCallback.h"
#include "server/zone/objects/player/sui/listbox/SuiListBox.h"
#include "server/zone/Zone.h"

HQDefenseStatusSuiCallback::HQDefenseStatusSuiCallback(ZoneServer* server) : SuiCallback(server) {
}

void HQDefenseStatusSuiCallback::run(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args) {
	bool cancelPressed = (eventIndex == 1);

	if (cancelPressed || !suiBox->isListBox() || player == nullptr)
		return;

	ManagedReference<SceneObject*> obj = suiBox->getUsingObject().get();

	if (obj == nullptr || !obj->isBuildingObject())
		return;

	ManagedReference<BuildingObject*> building = cast<BuildingObject*>(obj.get());

	GCWManager* gcwMan = player->getZone()->getGCWManager();

	if (gcwMan == nullptr)
		return;

	bool otherPressed = Bool::valueOf(args->get(0).toString());
	int indx = Integer::valueOf(args->get(1).toString());

	if (indx == -1)
		return;

	SuiListBox* listBox = cast<SuiListBox*>(suiBox);

	uint64 turretOID = listBox->getMenuObjectID(indx);

	if (otherPressed)
		gcwMan->sendRemoveDefenseConfirmation(building, player, turretOID);
	else
		gcwMan->sendBaseDefenseStatus(player, building);
}