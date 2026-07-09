/*
 * SpaceCommTimerTask.h
 *
 *  Created on: Jan 31, 2023
 *      Author: Phoenix
 */

#pragma once

#include "server/zone/Zone.h"
#include "server/zone/objects/scene/SceneObject.h"
#include "server/zone/packets/object/StopNpcConversation.h"
#include "server/zone/objects/player/sessions/ConversationSession.h"

class SpaceCommTimerTask : public Task, public Logger {
	ManagedWeakReference<CreatureObject*> play;
	uint64 shipID;

protected:
	int convoLength;

public:
	SpaceCommTimerTask(CreatureObject* playerCreo, uint64 oid);

	void run();
};
