#include "SpiceDownerAnimationTask.h"

SpiceDownerAnimationTask::SpiceDownerAnimationTask(CreatureObject* player, uint32 debuffCRC) : Task() {
	this->player = player;
	this->debuffCRC = debuffCRC;
}

void SpiceDownerAnimationTask::run() {
	if (player == nullptr)
		return;

	Locker locker(player);

	player->removePendingTask("spice_downer_animation");

	// If debuff is still active, perform animation and reschedule
	if (player->hasBuff(debuffCRC)) {
		player->doAnimation("heavy_cough_vomit");
		reschedule(15000);
	}
}