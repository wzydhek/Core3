#include "InstrumentPulseTask.h"

InstrumentPulseTask::InstrumentPulseTask(Instrument* inst) {
	instrument = inst;
}

void InstrumentPulseTask::run() {
	ManagedReference<Instrument*> strongRef = instrument.get();

	if (strongRef == nullptr)
		return;

	Locker locker(strongRef);

	ManagedReference<CreatureObject*> spawnerPlayer = strongRef->getSpawnerPlayer().get();

	if (spawnerPlayer == nullptr || !spawnerPlayer->isPlayerCreature() || !spawnerPlayer->getPlayerObject()->isOnline() || spawnerPlayer->getParentID() != strongRef->getParentID() || !strongRef->isInRange(spawnerPlayer, 8.0f)) {
		strongRef->destroyObjectFromWorld(true);
		return;
	}

	reschedule(5 * 1000); // 5 seconds
}