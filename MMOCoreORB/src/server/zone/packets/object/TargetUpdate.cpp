#include "TargetUpdate.h"
#include "server/zone/ZoneServer.h"

TargetUpdateCallback::TargetUpdateCallback(ObjectControllerMessageCallback* objectControllerCallback) : MessageCallback(objectControllerCallback->getClient(), objectControllerCallback->getServer()), size(0), targetID(0), objectControllerMain(objectControllerCallback) {
}

void TargetUpdateCallback::parse(Message* message) {
	size = message->parseInt();
	targetID = message->parseLong();
}

void TargetUpdateCallback::run() {
	ManagedReference<CreatureObject*> object = client->getPlayer();

	if (object == nullptr) {
		return;
	}

	if (object->getTargetID() != targetID) {
		setPlayerTargetID(object);
	}

	if (object->isPilotingShip()) {
		setShipTargetID(object);
	}
}

void TargetUpdateCallback::setPlayerTargetID(CreatureObject* object) {
	if (targetID != 0) {
		ManagedReference<SceneObject*> target = object->getZoneServer()->getObject(targetID);

		if (target != nullptr) {
			object->notifyObservers(ObserverEventType::PLAYERCHANGEDTARGET, target);
		} else {
			targetID = 0;
		}
	}

	object->setTargetID(targetID, true);
}

void TargetUpdateCallback::setShipTargetID(CreatureObject* object) {
	auto root = object->getRootParent();

	if (root == nullptr || !root->isShipObject()) {
		return;
	}

	auto ship = root->asShipObject();

	if (ship == nullptr || ship->getShipTargetID() == targetID) {
		return;
	}

	Locker cLock(root, object);
	ship->setShipTargetID(targetID, true);
}