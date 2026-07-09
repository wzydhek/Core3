#include "ShutdownSequenceTask.h"

ShutdownSequenceTask::ShutdownSequenceTask(GCWManager* gcwMan, BuildingObject* building, CreatureObject* player, SceneObject* term, bool isDestruction) {
	gcwManager = gcwMan;
	buildingObject = building;
	bDestruction = isDestruction;
	creature = player;
	hqTerminal = term;
}

void ShutdownSequenceTask::run() {
	if (buildingObject == nullptr || gcwManager == nullptr)
		return;

	if (bDestruction)
		gcwManager->scheduleBaseDestruction(buildingObject, creature);
	else
		gcwManager->startAbortSequenceDelay(buildingObject, creature, hqTerminal);
}