#include "FishingSplashEvent.h"

FishingSplashEvent::FishingSplashEvent(SceneObject* splashObj) : Task(1000) {
	splashWeak = splashObj;
}

void FishingSplashEvent::run() {
	auto splash = splashWeak.get();

	if (splash == nullptr)
		return;

	auto zoneProcServer = splash->getZoneProcessServer();

	if (zoneProcServer == nullptr)
		return;

	ManagedReference<FishingManager*> fishingManager = zoneProcServer->getFishingManager();

	if (fishingManager == nullptr)
		return;

	try {
		Locker splashLocker(splash);

		fishingManager->removeSplash(splash);
	} catch (...) {
		throw;
	}
}