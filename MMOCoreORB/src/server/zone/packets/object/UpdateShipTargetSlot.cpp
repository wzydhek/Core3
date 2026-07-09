#include "UpdateShipTargetSlot.h"
#include "server/zone/objects/creature/CreatureObject.h"
#include "server/zone/objects/ship/ShipObject.h"

UpdateShipTargetSlotCallback::UpdateShipTargetSlotCallback(ObjectControllerMessageCallback* objectControllerCallback) : MessageCallback(objectControllerCallback->getClient(), objectControllerCallback->getServer()), objectControllerMain(objectControllerCallback) {
	size = 0;
	targetSlot = Components::SIZE;
}

void UpdateShipTargetSlotCallback::parse(Message* message) {
	size = message->parseInt();
	targetSlot = message->parseInt();
}

void UpdateShipTargetSlotCallback::run() {
	if (targetSlot <= Components::CHASSIS || targetSlot >= Components::SIZE) {
		return;
	}

	ManagedReference<CreatureObject*> creature = client->getPlayer();

	if (creature == nullptr || !creature->isPilotingShip()) {
		return;
	}

	ManagedReference<SceneObject*> rootParent = creature->getRootParent();

	if (rootParent == nullptr || !rootParent->isShipObject()) {
		return;
	}

	auto ship = rootParent->asShipObject();

	if (ship == nullptr || ship->getShipTargetSlot() == targetSlot) {
		return;
	}

	Locker cLock(ship, creature);
	ship->setShipTargetSlot(targetSlot, true);
}