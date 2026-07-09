#include "server/zone/Zone.h"
#include "DefuseMineTask.h"

DefuseMineTask::DefuseMineTask(CreatureObject* player, WeaponObject* weapon, TangibleObject* minefield) {
	weakPlayer = player;
	weakWeapon = weapon;
	weakMinefield = minefield;
}

void DefuseMineTask::run() {
	auto player = weakPlayer.get();

	if (player == nullptr) {
		return;
	}

	Locker lock(player);

	auto minefield = weakMinefield.get();

	if (minefield == nullptr) {
		return;
	}

	Locker cLock(minefield, player);

	if (!minefield->isInRange(player, 5.f)) {
		player->sendSystemMessage("@container_error_message:container09"); // "You are out of range."
		return;
	}

	auto weapon = weakWeapon.get();

	if (weapon == nullptr) {
		return;
	}

	// Lets do some form of roll on this
	if ((System::random(MAX_CHANCE) > ROLL_CHANCE) || (player->getPosture() != CreaturePosture::CROUCHED)) {
		// Player has failed to defuse the mine
		player->sendSystemMessage("You have failed to defuse the mine...");

		// Schedule an attack task
		Reference<MinefieldAttackTask*> task = new MinefieldAttackTask(minefield, player);

		if (task != nullptr) {
			task->schedule(250);
		}

		return;
	}

	Locker weaponLock(weapon, player);

	// Destroy the mine
	weapon->destroyObjectFromWorld(true);
	weapon->destroyObjectFromDatabase(true);

	// Send player the success message
	player->sendSystemMessage("You succesffully disarm and dismantle an enemy mine.");

	// Set their posture upright
	player->setPosture(CreaturePosture::UPRIGHT, true, true);
}