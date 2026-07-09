#include "ClearThreatStateTask.h"
#include "server/zone/objects/tangible/threat/ThreatMap.h"

ClearThreatStateTask::ClearThreatStateTask(TangibleObject* me, TangibleObject* tar, uint64 st) {
	self = me;
	target = tar;
	state = st;
}

void ClearThreatStateTask::run() {
	Locker locker(self);
	ThreatMap* threatMap = self->getThreatMap();
	threatMap->clearThreatState(target, state);
}