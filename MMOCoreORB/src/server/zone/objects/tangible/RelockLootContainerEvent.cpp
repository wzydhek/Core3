#include "RelockLootContainerEvent.h"

RelockLootContainerEvent::RelockLootContainerEvent(Container* object) {
	container = object;
	container->setRelockingStatus(true);
}

void RelockLootContainerEvent::run() {
	Locker locker(container);

	container->setSliced(false);
	container->setRelockingStatus(false);

	if ((System::random(100)) < container->getLockChance()) {
		container->setSliceable(true);
		container->setLockedStatus(true);
	} else {
		container->setLockedStatus(false);
		container->setSliceable(false);
	}
}