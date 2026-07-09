#include "PlayerObjectDeltaMessage3.h"

PlayerObjectDeltaMessage3::PlayerObjectDeltaMessage3(PlayerObject* pl) : DeltaMessage(pl->getObjectID(), 0x504C4159, 3) {
	ghost = pl;
}

void PlayerObjectDeltaMessage3::updatePlayerBitmasks() {
	startUpdate(0x05);
	insertInt(0x04);

	const PlayerBitmasks* playerBits = ghost->getPlayerBitmasks();

	for (int i = 0; i < 4; ++i) {
		uint32 bit = playerBits->getBitmask(i);
		insertInt(bit);
	}
}

void PlayerObjectDeltaMessage3::updateProfileBitmasks() {
	startUpdate(0x06);
	insertInt(0x04);
	insertInt(0);
	insertInt(0);
	insertInt(0);
	insertInt(0);
}

void PlayerObjectDeltaMessage3::setCurrentTitle(const String& pTitle) {
	startUpdate(0x07);
	insertAscii(pTitle);
}

void PlayerObjectDeltaMessage3::setBirthDate() {
	startUpdate(0x08);
	insertInt(ghost->getBirthDate());
}

void PlayerObjectDeltaMessage3::setTotalPlayTime() {
	startUpdate(0x09);
	insertInt(ghost->getTotalPlayedTime());
}