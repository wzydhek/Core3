#include "PlayerObjectMessage3.h"

PlayerObjectMessage3::PlayerObjectMessage3(PlayerObject* ghost) : IntangibleObjectMessage3(ghost, 0x504C4159, 0x0B) {
	// Player Bitmasks
	insertInt(0x04);
	const PlayerBitmasks* playerBits = ghost->getPlayerBitmasks();

	for (int i = 0; i < 4; ++i) {
		uint32 bit = playerBits->getBitmask(i);
		insertInt(bit);
	}

	// Profile Settings
	insertInt(0x04);
	insertInt(0);
	insertInt(0);
	insertInt(0);
	insertInt(0);

	// Skill Title
	insertAscii(ghost->getTitle());

	// Born Date
	insertInt(ghost->getBirthDate());

	// Total Play Time
	insertInt(ghost->getTotalPlayedTime());

	insertInt(0x6C2);
	insertInt(0xDC62);
	insertInt(0x23);

	setSize();
}