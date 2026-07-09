#include "InsertAstromechIntoShipTask.h"

InsertAstromechIntoShipTask::InsertAstromechIntoShipTask(ShipObject* shipObj) : shipObj(shipObj) {
	setLoggingName("InsertPlayerToShipTask");
}

void InsertAstromechIntoShipTask::run() {
	auto ship = shipObj.get();

	if (ship == nullptr || !ship->hasSlotDescriptor("ship_droid")) {
		return;
	}

	auto player = ship->getOwner().get();

	if (player == nullptr) {
		return;
	}

	auto shipZone = ship->getLocalZone();

	if (shipZone == nullptr) {
		return;
	}

	auto zoneServer = ship->getZoneServer();

	if (zoneServer == nullptr) {
		return;
	}

	ManagedReference<SceneObject*> droidControlDeviceRef = zoneServer->getObject(ship->getShipDroidID());

	if (droidControlDeviceRef == nullptr || !droidControlDeviceRef->isControlDevice()) {
		return;
	}

	auto droidControlDevice = dynamic_cast<PetControlDevice*>(droidControlDeviceRef.get());

	if (droidControlDevice == nullptr)
		return;

	auto droidObject = dynamic_cast<DroidObject*>(droidControlDevice->getControlledObject());

	if (droidObject == nullptr) {
		return;
	}

	Locker sLock(ship);
	Locker cLock(droidObject, ship);

	droidObject->setMovementCounter(0);
	droidObject->setDirection(1, 0, 0, 0);
	droidObject->switchZone(shipZone->getZoneName(), 0, 0, 0, ship->getObjectID(), false, PlayerArrangement::RIDER);
}