/*
 * GroupLootTask.h
 *
 *  Created on: March 8, 2015
 *      Author: Anakis
 */

#pragma once

#include "server/chat/StringIdChatParameter.h"
#include "server/zone/objects/group/GroupObject.h"
#include "server/zone/managers/group/GroupManager.h"
#include "server/zone/objects/player/sessions/LootLotterySession.h"
#include "server/zone/objects/transaction/TransactionLog.h"

class GroupLootTask : public Task {
	ManagedReference<GroupObject*> group;
	ManagedReference<CreatureObject*> player;
	ManagedReference<AiAgent*> corpse;

	bool lootAll;

public:
	GroupLootTask(GroupObject* gr, CreatureObject* pl, AiAgent* ai, bool all);

	void run();

	void splitCredits();

	bool membersInRange();

};
