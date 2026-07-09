#include "LotteryDroidPulseTask.h"

LotteryDroidPulseTask::LotteryDroidPulseTask(LotteryDroid* dr) {
	droid = dr;
}

void LotteryDroidPulseTask::run() {
	ManagedReference<LotteryDroid*> strongRef = droid.get();

	if (strongRef == nullptr)
		return;

	Locker locker(strongRef);

	int gameStatus = strongRef->getGameStatus();

	if (gameStatus == LotteryDroid::GAMESTARTED) {
		strongRef->endGame();

		// Resets duration to so that droid will stay in world for 72 hours after game ends to give lottery results
		this->reschedule(72 * 60 * 60 * 1000); // 72 hours
	} else if (gameStatus == LotteryDroid::GAMEENDED) {
		EventPerkDataComponent* gameData = cast<EventPerkDataComponent*>(strongRef->getDataObjectComponent()->get());

		if (gameData == nullptr)
			return;

		EventPerkDeed* deed = gameData->getDeed();

		if (deed == nullptr)
			return;

		deed->activateRemoveEvent(true);
	}
}