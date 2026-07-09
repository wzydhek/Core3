#include "CompleteMissionAfterCertainTimeTask.h"

CompleteMissionAfterCertainTimeTask::CompleteMissionAfterCertainTimeTask(MissionObjective* objective) {
	this->objective = objective;
}

void CompleteMissionAfterCertainTimeTask::run() {
	// Complete mission.
	objective->complete();
}