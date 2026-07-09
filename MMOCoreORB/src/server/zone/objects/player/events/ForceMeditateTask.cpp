#include "ForceMeditateTask.h"

ForceMeditateTask::ForceMeditateTask(CreatureObject* pl) {
	player = pl;
}

void ForceMeditateTask::setMoodString(const String& ms) {
	moodString = ms;
}

String ForceMeditateTask::getMoodString() {
	return moodString;
}

void ForceMeditateTask::run() {
	Locker playerLocker(player);

	try {
		Reference<ForceMeditateTask*> fmeditateTask = player->getPendingTask("forcemeditate").castTo<ForceMeditateTask*>();

		if (!player->isMeditating())
			return;

		if (fmeditateTask != nullptr)
			fmeditateTask->reschedule(5000);

	} catch (Exception& e) {
		player->error("unreported exception caught in ForceMeditateTask::activate");
	}
}