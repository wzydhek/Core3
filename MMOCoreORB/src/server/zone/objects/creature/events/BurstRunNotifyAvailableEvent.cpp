#include "BurstRunNotifyAvailableEvent.h"

BurstRunNotifyAvailableEvent::BurstRunNotifyAvailableEvent(CreatureObject* cr) : Task() {
	creo = cr;
}

void BurstRunNotifyAvailableEvent::run() {
	ManagedReference<CreatureObject*> creature = creo.get();

	if (creature == nullptr)
		return;

	Locker locker(creature);

	creature->removePendingTask("burst_run_notify");
	creature->sendSystemMessage("@combat_effects:burst_run_not_tired"); //"You are no longer tired.";
}