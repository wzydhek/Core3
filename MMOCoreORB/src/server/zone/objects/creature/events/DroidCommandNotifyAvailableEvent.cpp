#include "DroidCommandNotifyAvailableEvent.h"

DroidCommandNotifyAvailableEvent::DroidCommandNotifyAvailableEvent(CreatureObject* cr) : Task() {
	creo = cr;
}

void DroidCommandNotifyAvailableEvent::run() {
	ManagedReference<CreatureObject*> creature = creo.get();

	if (creature == nullptr)
		return;

	Locker locker(creature);

	creature->removePendingTask("droid_command_notify");
	creature->sendSystemMessage("@space/space_interaction:droid_delay_ready"); // Droid command completed. Ready for new command.
}