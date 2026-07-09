#include "PlayerObjectDeltaMessage8.h"

PlayerObjectDeltaMessage8::PlayerObjectDeltaMessage8(PlayerObjectImplementation* pl) : DeltaMessage(pl->getObjectID(), 0x504C4159, 8) {
	play = pl;
}

void PlayerObjectDeltaMessage8::updateForcePower() {
	addIntUpdate(0x02, play->getForcePower());
}

void PlayerObjectDeltaMessage8::updateForcePowerMax() {
	addIntUpdate(0x03, play->getForcePowerMax());
}
