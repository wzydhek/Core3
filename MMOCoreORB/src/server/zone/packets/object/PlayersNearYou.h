/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions. */

#pragma once

#include "ObjectControllerMessage.h"
#include "server/zone/objects/creature/CreatureObject.h"

class PlayersNearYouMessage : public ObjectControllerMessage {
public:
	PlayersNearYouMessage(CreatureObject* creo);

	void addFoundPlayer(CreatureObject* player);

	void insertPlayerCounter(uint32 foundCount);

};
