#include "PlayerIncapacitationRecoverTask.h"
#include "server/zone/objects/player/PlayerObject.h"

PlayerIncapacitationRecoverTask::PlayerIncapacitationRecoverTask(CreatureObject* pl, bool deadRecovery) : Task() {
	player = pl;

	this->deadRecovery = deadRecovery;
}

PlayerIncapacitationRecoverTask::~PlayerIncapacitationRecoverTask() {
	/*if (enQueued) {
		System::out << "ERROR: PlayerRecoveryEvent scheduled event deleted\n";
		raise(SIGSEGV);
	}*/
}

void PlayerIncapacitationRecoverTask::run() {
	try {
		Locker playerLocker(player);

		PlayerObject* ghost = player->getPlayerObject();

		if (ghost == nullptr) {
			return;
		}

		if (!deadRecovery)
			player->removePendingTask("incapacitationRecovery");

		if (!deadRecovery && !player->isIncapacitated())
			return;
		else if (deadRecovery && !player->isDead())
			return;

		ghost->setCloning(false);

		int health = player->getHAM(CreatureAttribute::HEALTH);

		if (health < 0)
			player->setHAM(CreatureAttribute::HEALTH, 1);

		int action = player->getHAM(CreatureAttribute::ACTION);

		if (action < 0)
			player->setHAM(CreatureAttribute::ACTION, 1);

		int mind = player->getHAM(CreatureAttribute::MIND);

		if (mind < 0)
			player->setHAM(CreatureAttribute::MIND, 1);

		player->removeFeignedDeath();

		player->setPosture(CreaturePosture::UPRIGHT, true, true);

		player->notifyObservers(ObserverEventType::CREATUREREVIVED, nullptr, 0);

		if (ghost->getForcePowerMax() > 0 && ghost->getForcePower() < ghost->getForcePowerMax()) {
			ghost->activateForcePowerRegen();
		}

		if (deadRecovery) {
			player->playEffect("clienteffect/player_clone_compile.cef");
			player->notifyObservers(ObserverEventType::PLAYERCLONED, player, 0);
			player->broadcastPvpStatusBitmask();
		}
	} catch (Exception& e) {
		player->error("unreported exception caught in PlayerRecoveryEvent::activate");
	}
}