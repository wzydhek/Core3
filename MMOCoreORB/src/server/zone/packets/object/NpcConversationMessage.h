/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "ObjectControllerMessage.h"
#include "server/zone/objects/creature/CreatureObject.h"
#include "server/chat/StringIdChatParameter.h"

//TODO: This needs more research!

class NpcConversationMessage : public ObjectControllerMessage {
public:

	NpcConversationMessage(CreatureObject* creo, const UnicodeString& message);

	NpcConversationMessage(CreatureObject* creo, StringIdChatParameter& stringid);
};
