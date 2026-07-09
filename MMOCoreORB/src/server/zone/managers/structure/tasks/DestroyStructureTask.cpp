#include "DestroyStructureTask.h"

DestroyStructureTask::DestroyStructureTask(StructureObject* structure, bool doEffect, bool killStuff) {
	structureObject = structure;
	playEffect = doEffect;
	killOccupants = killStuff;

	setCustomTaskQueue("slowQueue");
}

void DestroyStructureTask::run() {
	Locker locker(structureObject);

	ManagedReference<Zone*> zone = structureObject->getZone();

	if (zone == nullptr)
		return;

	ZoneServer* zoneServer = structureObject->getZoneServer();

	if (zoneServer != nullptr && zoneServer->isServerLoading()) {
		schedule(1000);

		return;
	}

	float x = structureObject->getPositionX();
	float y = structureObject->getPositionY();
	float z = zone->getHeight(x, y);

	if (playEffect) {
		PlayClientEffectLoc* explodeLoc = new PlayClientEffectLoc("clienteffect/combat_explosion_lair_large.cef", structureObject->getZone()->getZoneName(), structureObject->getPositionX(), structureObject->getPositionZ(), structureObject->getPositionY());
		structureObject->broadcastMessage(explodeLoc, false);
	}

	if (structureObject->isBuildingObject()) {
		ManagedReference<BuildingObject*> buildingObject = cast<BuildingObject*>(structureObject.get());

		for (uint32 i = 1; i <= buildingObject->getTotalCellNumber(); ++i) {
			ManagedReference<CellObject*> cellObject = buildingObject->getCell(i);

			if (cellObject == nullptr)
				continue;

			int childObjects = cellObject->getContainerObjectsSize();

			if (childObjects <= 0)
				continue;

			// Traverse the vector backwards since the size will change as objects are removed.
			for (int j = childObjects - 1; j >= 0; --j) {
				ManagedReference<SceneObject*> obj = cellObject->getContainerObject(j);

				if (obj->isPlayerCreature() || obj->isPet()) {
					CreatureObject* playerCreature = cast<CreatureObject*>(obj.get());

					structureObject->unlock();

					try {
						Locker plocker(playerCreature);

						if (killOccupants) {
							playerCreature->inflictDamage(playerCreature, 0, 9999999, true, true);
							playerCreature->inflictDamage(playerCreature, 3, 9999999, true, true);
							playerCreature->inflictDamage(playerCreature, 6, 9999999, true, true);
						}

						playerCreature->teleport(x, z, y, 0);
					} catch (...) {
						playerCreature->error("unreported exception caught while teleporting");
					}

					structureObject->wlock();
				}
			}
		}
	}

	// Get the owner of the structure, and remove the structure from their possession.
	ManagedReference<SceneObject*> owner = zone->getZoneServer()->getObject(structureObject->getOwnerObjectID());

	if (owner != nullptr) {
		ManagedReference<SceneObject*> ghost = owner->getSlottedObject("ghost");

		if (ghost != nullptr && ghost->isPlayerObject()) {
			PlayerObject* playerObject = cast<PlayerObject*>(ghost.get());
			playerObject->removeOwnedStructure(structureObject);

			uint64 waypointID = structureObject->getWaypointID();

			if (waypointID != 0)
				playerObject->removeWaypoint(waypointID, true, true);
		}
	}

	structureObject->destroyObjectFromWorld(true);
	structureObject->notifyObservers(ObserverEventType::OBJECTDESTRUCTION, structureObject, 0);
	structureObject->destroyObjectFromDatabase(true);
}