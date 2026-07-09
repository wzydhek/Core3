#include "ProposeUnityExpiredTask.h"

ProposeUnityExpiredTask::ProposeUnityExpiredTask(CreatureObject* player) : Task() {
	this->player = player;
}

void ProposeUnityExpiredTask::run() {
	if (player == nullptr)
		return;

	Locker locker(player);
	player->removePendingTask("propose_unity");

	ManagedReference<ProposeUnitySession*> proposeUnitySession = player->getActiveSession(SessionFacadeType::PROPOSEUNITY).castTo<ProposeUnitySession*>();
	if (proposeUnitySession != nullptr) {
		if (player->getObjectID() == proposeUnitySession->getAskingPlayer()) {
			player->sendSystemMessage("@unity:expire_player"); // "The unity proposal you extended has expired."
		} else {
			player->sendSystemMessage("@unity:expire_target"); // "The unity proposal extended to you has expired."
		}
		player->dropActiveSession(SessionFacadeType::PROPOSEUNITY);
	}
}