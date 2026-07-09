#include "DonateMineSuiCallback.h"
#include "server/zone/objects/player/sui/listbox/SuiListBox.h"

DonateMineSuiCallback::DonateMineSuiCallback(ZoneServer* server) : SuiCallback(server) {
}

void DonateMineSuiCallback::run(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args) {
	bool cancelPressed = (eventIndex == 1);

	if (cancelPressed || !suiBox->isListBox() || player == nullptr) {
		return;
	}

	ManagedReference<SceneObject*> minefield = suiBox->getUsingObject().get();

	if (minefield == nullptr || (!minefield->isMinefield() && !minefield->isTurret())) {
		return;
	}

	Locker lock(minefield);

	int objectCount = minefield->getContainerObjectsSize();
	int volumeLimit = minefield->getContainerVolumeLimit();

	if (objectCount >= volumeLimit) {
		player->sendSystemMessage("@container_error_message:container03"); // This container is full.
		return;
	}

	SuiListBox* listBox = cast<SuiListBox*>(suiBox);

	if (listBox == nullptr) {
		return;
	}

	auto zoneServer = minefield->getZoneServer();

	if (zoneServer == nullptr) {
		return;
	}

	int indx = Integer::valueOf(args->get(0).toString());

	uint64 objectid = listBox->getMenuObjectID(indx);

	ManagedReference<SceneObject*> mineSceneO = zoneServer->getObject(objectid).get();

	if (mineSceneO == nullptr || mineSceneO->getGameObjectType() != SceneObjectType::MINE) {
		return;
	}

	auto mine = mineSceneO.castTo<WeaponObject*>();

	if (mine == nullptr) {
		return;
	}

	Locker clock(mine, minefield);

	if (!minefield->transferObject(mine, -1, true)) {
		return;
	}

	mine->sendDestroyTo(player);

	minefield->broadcastObject(mine, false);
}