#include "FlagGamePulseTask.h"

FlagGamePulseTask::FlagGamePulseTask(FlagGame* ga) {
	game = ga;
}

void FlagGamePulseTask::run() {
	if (game == nullptr || game->isGameEnded())
		return;

	Locker locker(game);

	uint32 factionControl = game->getFactionControl();

	if (factionControl == Factions::FACTIONREBEL) {
		game->increaseRebelScore();
	} else if (factionControl == Factions::FACTIONIMPERIAL) {
		game->increaseImperialScore();
	}

	uint64 timeLimit = game->getTimeLimit();
	Time* startTime = game->getGameStartTime();

	Time currentTime;
	uint64 timeDelta = currentTime.getMiliTime() - startTime->getMiliTime();

	if (timeDelta >= timeLimit) {
		game->endGame();
	} else {
		this->reschedule(15 * 1000); // 15 second pulse
	}
}