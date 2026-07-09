#include "SecuritySliceTask.h"

SecuritySliceTask::SecuritySliceTask(GCWManager* gcwMan, TangibleObject* term, CreatureObject* player) {
	gcwManager = gcwMan;
	terminal = term;
	creature = player;
}

void SecuritySliceTask::run() {
	if (terminal == nullptr || gcwManager == nullptr)
		return;

	gcwManager->completeSecuritySlice(creature, terminal);
}