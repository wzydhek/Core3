#include "SampleResultsTask.h"

SampleResultsTask::SampleResultsTask(ManagedReference<CreatureObject*> play, const ResourceSpawner* spawner, float d, String rname) {
	playerCreature = play;
	resourceSpawner = spawner;
	density = d;
	resname = rname;
}

void SampleResultsTask::run() {
	Locker locker(playerCreature);

	TransactionLog trx(TrxCode::HARVESTED, playerCreature);
	resourceSpawner->sendSampleResults(trx, playerCreature, density, resname);
	playerCreature->removePendingTask("sampleresults");
	trx.commit();
}