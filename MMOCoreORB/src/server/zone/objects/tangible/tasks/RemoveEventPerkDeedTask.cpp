#include "RemoveEventPerkDeedTask.h"

RemoveEventPerkDeedTask::RemoveEventPerkDeedTask(EventPerkDeed* deed) {
	weakDeed = deed;
}

void RemoveEventPerkDeedTask::run() {
	auto deed = weakDeed.get();

	if (deed == nullptr) {
		return;
	}

	Locker locker(deed);

	ManagedReference<TangibleObject*> generatedObject = deed->getGeneratedObject().get();
	ManagedReference<CreatureObject*> player = deed->getOwner().get();

	if (generatedObject != nullptr) {
		EventPerkDataComponent* data = cast<EventPerkDataComponent*>(generatedObject->getDataObjectComponent()->get());

		if (data != nullptr) {
			auto npcActor = data->getActor();

			if (npcActor != nullptr) {
				Locker actorLock(npcActor, deed);

				npcActor->destroyObjectFromWorld(true);
				npcActor->destroyObjectFromDatabase(true);
			}
		}

		Locker clocker(generatedObject, deed);

		// Destroy any child objects
		generatedObject->destroyChildObjects();

		// Destroy the Perk Object and anything within
		generatedObject->destroyObjectFromWorld(true);
		generatedObject->destroyObjectFromDatabase(true);
	} else if (player != nullptr) {
		player->sendSystemMessage("@event_perk:deed_expired"); // Your unused Rental Deed expired and has been removed from your inventory.
	}

	// Destroy the Deed
	deed->destroyObjectFromWorld(true);
	deed->destroyObjectFromDatabase();
}