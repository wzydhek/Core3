#include "FireworkLaunchEvent.h"

FireworkLaunchEvent::FireworkLaunchEvent(CreatureObject* player, FireworkObject* firework, int removeDelay) : Task(1000) {
	this->firework = firework;
	this->player = player;
	this->removeDelay = removeDelay;
}

void FireworkLaunchEvent::run() {
	ManagedReference<FireworkObject*> firework = this->firework.get();
	ManagedReference<CreatureObject*> player = this->player.get();

	if (firework == nullptr || player == nullptr)
		return;

	try {
		Locker locker(firework);

		firework->completeLaunch(player, removeDelay);
	} catch (Exception& e) {
		player->error("unreported exception on FireworkLaunchEvent::run()");
	}

	this->firework = nullptr;
	this->player = nullptr;
}