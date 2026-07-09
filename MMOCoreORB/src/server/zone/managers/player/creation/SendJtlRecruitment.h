/*
 * SendJtlRecruitment.h
 *
 *  Created on: 2024-10-23
 *	Author: Hakry
 */

#pragma once

#include "server/zone/objects/creature/CreatureObject.h"
#include "server/chat/ChatManager.h"

class SendJtlRecruitment : public Task {
	ManagedWeakReference<CreatureObject*> weakPlayer;

public:
	SendJtlRecruitment(CreatureObject* player);

	void run();
};
