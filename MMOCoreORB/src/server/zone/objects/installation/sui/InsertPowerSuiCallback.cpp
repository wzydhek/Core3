#include "InsertPowerSuiCallback.h"

InsertPowerSuiCallback::InsertPowerSuiCallback(ZoneServer* server) : SuiCallback(server) {
}

void InsertPowerSuiCallback::run(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args) {
	bool cancelPressed = (eventIndex == 1);

	if (!suiBox->isTransferBox() || cancelPressed)
		return;

	if (args->size() < 2)
		return;

	uint32 energy = (uint64)Long::valueOf(args->get(1).toString());
	if (energy <= 0) {
		return;
	}

	ManagedReference<SceneObject*> object = suiBox->getUsingObject().get();

	if (object == nullptr || !object->isInstallationObject())
		return;

	InstallationObject* installation = cast<InstallationObject*>(object.get());

	ManagedReference<ResourceManager*> resourceManager = player->getZoneServer()->getResourceManager();

	// TODO: This should be handled in StructureManager

	Locker _lock(installation, player);

	uint32 energyFromPlayer = resourceManager->getAvailablePowerFromPlayer(player);

	if (energy > energyFromPlayer)
		return;

	installation->addPower(energy);
	resourceManager->removePowerFromPlayer(player, energy);

	StringIdChatParameter stringId("player_structure", "deposit_successful");
	stringId.setDI(energy);

	player->sendSystemMessage(stringId);

	stringId.setStringId("player_structure", "reserve_report");
	stringId.setDI(installation->getSurplusPower());

	player->sendSystemMessage(stringId);

	installation->updateToDatabase();
}