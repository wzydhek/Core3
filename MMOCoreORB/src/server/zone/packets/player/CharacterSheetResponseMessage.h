/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "engine/service/proto/BaseMessage.h"
#include "server/zone/objects/creature/CreatureObject.h"

class CharacterSheetResponseMessage : public BaseMessage {
public:
	CharacterSheetResponseMessage(CreatureObject* player);

};
