/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "ObjectControllerMessage.h"
#include "server/zone/objects/creature/CreatureObject.h"

class Biography : public ObjectControllerMessage {
public:
	Biography(CreatureObject* play, CreatureObject* player) : ObjectControllerMessage(play->getObjectID(), 0x1B, 0x1DB, true) {
		insertLong(player->getObjectID());

		PlayerObject* ghost = player->getPlayerObject();

		insertUnicode(ghost->getBiography());
	}

};
