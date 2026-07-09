/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "ObjectControllerMessage.h"
#include "server/zone/objects/creature/CreatureObject.h"

class StartNpcConversation : public ObjectControllerMessage {
public:
	StartNpcConversation(CreatureObject* creo, uint64 npcID, byte starter, const String& ascii, uint32 crc = 0);
};
