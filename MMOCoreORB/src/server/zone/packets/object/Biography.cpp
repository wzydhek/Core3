#include "Biography.h"
#include "server/zone/objects/player/PlayerObject.h"

Biography::Biography(CreatureObject* play, CreatureObject* player) : ObjectControllerMessage(play->getObjectID(), 0x1B, 0x1DB, true) {
	insertLong(player->getObjectID());

	PlayerObject* ghost = player->getPlayerObject();

	insertUnicode(ghost->getBiography());
}