#include "SampleTask.h"

SampleTask::SampleTask(CreatureObject* play, SurveyTool* tool) {
	playerCreature = play;
	surveyTool = tool;
	cancelled = false;
}

void SampleTask::run() {
	Locker playerLocker(playerCreature);

	if (!cancelled && playerCreature->getPendingTask("sample") != nullptr) {
		playerCreature->removePendingTask("sample");

		ManagedReference<SurveySession*> session = playerCreature->getActiveSession(SessionFacadeType::SURVEY).castTo<SurveySession*>();
		if (session != nullptr) {
			session->reSample();
		}
		return;
	}

	playerCreature->removePendingTask("sample");
	cancelled = false;
}

void SampleTask::stopSampling() {
	cancelled = true;
}

bool SampleTask::isCancelled() {
	return cancelled;
}