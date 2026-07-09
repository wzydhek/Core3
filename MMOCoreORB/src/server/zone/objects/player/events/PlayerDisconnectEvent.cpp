#include "PlayerDisconnectEvent.h"

PlayerDisconnectEvent::PlayerDisconnectEvent(PlayerObject* pl, bool isSafe) : Task(2000) {
	player = pl;
	isSafeArea = isSafe;
}

void PlayerDisconnectEvent::run() {
	ManagedReference<PlayerObject*> play = player.get();

	if (play == nullptr)
		return;

	ManagedReference<SceneObject*> par = play->getParent().get();

	Locker locker(par);

	try {
		play->clearDisconnectEvent();

		play->setLinkDead(isSafeArea);

		if (play->isOnline()) {
			play->disconnect(true, false);
		}

		play->notifyOffline();

	} catch (Exception& e) {
		play->error("Unreported Exception caught in PlayerDisconnectEvent::activate");

		play->clearDisconnectEvent();
	}
}