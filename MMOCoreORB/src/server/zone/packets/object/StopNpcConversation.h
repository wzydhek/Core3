/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "ObjectControllerMessage.h"
#include "server/zone/objects/creature/CreatureObject.h"

class StopNpcConversation : public ObjectControllerMessage {
public:
	StopNpcConversation(CreatureObject* creo, uint64 npcID);
};
