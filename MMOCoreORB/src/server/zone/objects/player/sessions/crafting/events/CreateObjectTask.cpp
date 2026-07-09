#include "CreateObjectTask.h"
#include "server/zone/managers/object/ObjectManager.h"
#include "server/zone/ZoneServer.h"

CreateObjectTask::CreateObjectTask(CreatureObject* player, CraftingTool* tool, bool pract) : Task() {
	craftingTool = tool;
	crafter = player;
	practice = pract;
}

void CreateObjectTask::run() {
	Locker locker(crafter);
	Locker clocker(craftingTool, crafter);

	craftingTool->setCountdownTimer(0, true);

	auto prototype = craftingTool->getPrototype();

	if (prototype == nullptr || practice) {
		craftingTool->removeAllContainerObjects();
		craftingTool->setReady();

		if (practice && prototype != nullptr)
			crafter->notifyObservers(ObserverEventType::PROTOTYPECREATED, prototype, 1);

		return;
	}

	ObjectManager* objectManager = crafter->getZoneServer()->getObjectManager();
	objectManager->persistSceneObjectsRecursively(prototype, 1);

	ManagedReference<SceneObject*> inventory = crafter->getInventory();

	// The check for space in the players inventory has to be done here instead of in isContainerFullRecursive due to the object being in the crafting tool already.
	if (inventory != nullptr && craftingTool->isASubChildOf(crafter) && !(inventory->getContainerVolumeLimit() <= (inventory->getCountableObjectsRecursive()))) {
		TransactionLog trx(crafter, inventory, prototype, TrxCode::CRAFTINGSESSION);

		if (inventory->transferObject(prototype, -1, true)) {
			crafter->sendSystemMessage("@system_msg:prototype_transferred");

			crafter->notifyObservers(ObserverEventType::PROTOTYPECREATED, prototype, 0);
			craftingTool->setReady();

			return;
		}
	}

	crafter->sendSystemMessage("@system_msg:prototype_not_transferred");
	craftingTool->setFinished();
}