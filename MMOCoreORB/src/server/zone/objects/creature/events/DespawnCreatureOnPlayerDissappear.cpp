#include "DespawnCreatureOnPlayerDissappear.h"
#include "server/zone/Zone.h"

DespawnCreatureOnPlayerDissappear::DespawnCreatureOnPlayerDissappear(AiAgent* creo) {
	creature = creo;

	auto zone = creo->getZone();

	if (zone != nullptr) {
		setCustomTaskQueue(zone->getZoneName());
	}
}

void DespawnCreatureOnPlayerDissappear::run() {
	ManagedReference<AiAgent*> strongRef = creature.get();

	if (strongRef == nullptr)
		return;

	Locker locker(strongRef);

	strongRef->clearDespawnEvent();

	Zone* zone = strongRef->getZone();

	if (zone == nullptr)
		return;

	if (!strongRef->getDespawnOnNoPlayerInRange())
		return;

	if (strongRef->getNumberOfPlayersInRange() <= 0) {
		strongRef->destroyObjectFromWorld(true);
		strongRef->notifyDespawn(zone);
	}
}