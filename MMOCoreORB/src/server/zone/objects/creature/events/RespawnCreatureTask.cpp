#include "RespawnCreatureTask.h"

RespawnCreatureTask::RespawnCreatureTask(AiAgent* cr, Zone* zn, int level) {
	creature = cr;
	zone = zn;
	this->level = level;

	setCustomTaskQueue(zone->getZoneName());
}

void RespawnCreatureTask::run() {
	if (creature == nullptr)
		return;

	Locker locker(creature);

	creature->respawn(zone, level);
}