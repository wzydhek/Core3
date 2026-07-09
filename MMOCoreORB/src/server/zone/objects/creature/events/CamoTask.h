/*
 * CamoTask.h
 *
 *  Created on: May 23, 2012
 *      Author: da
 */

#pragma once

#include "server/chat/StringIdChatParameter.h"
#include "server/zone/managers/player/PlayerManager.h"
#include "server/zone/objects/creature/CreatureObject.h"
#include "server/zone/objects/creature/buffs/ConcealBuff.h"
#include "server/zone/objects/creature/ai/AiAgent.h"

class CamoTask : public Task {
	ManagedWeakReference<CreatureObject*> player;
	ManagedWeakReference<CreatureObject*> creature;
	bool success;
	bool maskScent;

public:
	CamoTask(CreatureObject* pl, CreatureObject* creo, bool ms, bool succ);

	void run();
};
