/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "ObjectControllerMessage.h"

class StartingLocationListMessage : public ObjectControllerMessage {
public:
	StartingLocationListMessage(CreatureObject* creo)
			: ObjectControllerMessage(creo->getObjectID(), 0x1B, 0x1FC) {

		//Populate with PlayerManager::sendStartingLocationListTo()
	}
};
