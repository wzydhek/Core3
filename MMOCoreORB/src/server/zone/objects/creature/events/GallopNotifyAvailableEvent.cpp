#include "GallopNotifyAvailableEvent.h"

GallopNotifyAvailableEvent::GallopNotifyAvailableEvent(CreatureObject* cr) : Task() {
	creo = cr;
}

void GallopNotifyAvailableEvent::run() {
	ManagedReference<CreatureObject*> mount = creo.get();

	if (mount == nullptr)
		return;

	Locker locker(mount);

	mount->removePendingTask("gallop_notify");

	ManagedReference<CreatureObject*> owner = mount->getLinkedCreature().get();

	if (owner != nullptr)
		owner->sendSystemMessage("@combat_effects:mount_not_tired"); // Your mount is no longer winded.
}