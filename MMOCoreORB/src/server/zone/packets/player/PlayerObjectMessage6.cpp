#include "PlayerObjectMessage6.h"

PlayerObjectMessage6::PlayerObjectMessage6(PlayerObject* play) : BaseLineMessage(play->getObjectID(), 0x504C4159, 6, 0x03) {
	insertInt(0);

	uint8 privFlag = play->getPriviledgeFlag();

	insertByte(privFlag); // Developer/CSR Flag

	setSize();
}