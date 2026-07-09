#include "LootLotteryTimeoutTask.h"

LootLotteryTimeoutTask::LootLotteryTimeoutTask(LootLotterySession* ses) : Task() {
	session = ses;
}

void LootLotteryTimeoutTask::run() {
	if (session != nullptr)
		session->doLotteryDraw();
}