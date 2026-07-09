#include "VisibilityDecayTask.h"

VisibilityDecayTask::VisibilityDecayTask() : Task() {
}

void VisibilityDecayTask::run() {
	VisibilityManager::instance()->performVisiblityDecay();
	reschedule(VisibilityManager::instance()->getVisDecayTickRate() * 1000);
}