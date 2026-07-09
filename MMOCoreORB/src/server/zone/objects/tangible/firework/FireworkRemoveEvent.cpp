#include "FireworkRemoveEvent.h"

FireworkRemoveEvent::FireworkRemoveEvent(CreatureObject* player, StaticObject* firework) : Task(1000) {
	this->player = player;
	this->firework = firework;
}

void FireworkRemoveEvent::run() {
	if (firework == nullptr)
		return;

	try {
		Locker locker(firework);

		firework->destroyObjectFromWorld(true);
	} catch (Exception& e) {
		player->error("unreported exception on FireworkEvent::run()");
	}

	firework = nullptr;
	player = nullptr;
}