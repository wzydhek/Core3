#include "RemoveAggroTask.h"
#include "server/zone/objects/tangible/threat/ThreatMap.h"

RemoveAggroTask::RemoveAggroTask(TangibleObject* me, TangibleObject* cr, int va) {
	self = me;
	target = cr;
	value = va;
}

void RemoveAggroTask::run() {
	Locker locker(self);
	ThreatMap* threatMap = self->getThreatMap();
	threatMap->removeAggro(target, value);
}