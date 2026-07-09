#include "PlayerObjectDeltaMessage6.h"

PlayerObjectDeltaMessage6::PlayerObjectDeltaMessage6(PlayerObject* pl) : DeltaMessage(pl->getObjectID(), 0x504C4159, 6) {
	play = pl;
}

void PlayerObjectDeltaMessage6::setAdminLevel(uint8 level) {
	startUpdate(1);
	insertByte(level);
}