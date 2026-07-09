#include "SpawnLairMobileTask.h"

SpawnLairMobileTask::SpawnLairMobileTask(LairObject* lair, int spawnNum, String mobileStr, bool passive) {
	lairWeak = lair;
	spawnNumber = spawnNum;
	mobileString = mobileStr;
	spawnPassive = passive;
}

void SpawnLairMobileTask::run() {
	auto lairObject = lairWeak.get();

	if (lairObject == nullptr) {
		return;
	}

	if (lairObject->getZone() == nullptr) {
		return;
	}

	// lairObject->info(true) << "spawn lair mobile called for Lair: " << lairObject->getDisplayedName() << " ID: " << lairObject->getObjectID() << " Position: " << lairObject->getPosition().toString();

	Locker lock(lairObject);

	ManagedReference<LairObserver*> lairObserver = nullptr;
	SortedVector<ManagedReference<Observer*>> observers = lairObject->getObservers(ObserverEventType::OBJECTDESTRUCTION);

	for (int i = 0; i < observers.size(); i++) {
		lairObserver = cast<LairObserver*>(observers.get(i).get());

		if (lairObserver != nullptr) {
			break;
		}
	}

	if (lairObserver == nullptr) {
		return;
	}

	lairObserver->spawnLairMobile(lairObject, spawnNumber, mobileString, spawnPassive);
}