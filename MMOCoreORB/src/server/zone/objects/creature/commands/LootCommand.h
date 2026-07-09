/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "QueueCommand.h"
#include "server/zone/objects/creature/ai/AiAgent.h"
#include "server/zone/objects/scene/SceneObject.h"

class LootCommand : public QueueCommand {

public:
	enum {
		NOPICKUPITEMS = 0,
		ITEMFOROTHER = 1,
		PICKEDANDREMAINING = 2,
		PICKEDANDEMPTY = 3
	};

	LootCommand(const String& name, ZoneProcessServer* server);

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const;

	int pickupOwnedItems(AiAgent* ai, CreatureObject* creature, SceneObject* lootContainer) const;
};

