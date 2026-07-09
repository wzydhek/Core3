#include "DisseminateExperienceTask.h"

DisseminateExperienceTask::DisseminateExperienceTask(TangibleObject* obj, ThreatMap* threatMap, SynchronizedVector<ManagedReference<CreatureObject*>>* creatures, Zone* lairZone) : lair(obj), copyThreatMap(*threatMap), spawnedCreatures(*creatures), lairZone(lairZone) {
}

void DisseminateExperienceTask::run() {
	ManagedReference<TangibleObject*> strongRef = lair.get();

	if (strongRef == nullptr)
		return;

	Locker locker(strongRef);

	PlayerManager* playerManager = strongRef->getZoneServer()->getPlayerManager();
	playerManager->disseminateExperience(strongRef, &copyThreatMap, &spawnedCreatures, lairZone);
}