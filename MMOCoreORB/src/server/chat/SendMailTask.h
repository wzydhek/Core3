/*
 * SendMailTask.h
 *
 *  Created on: 14/01/2013
 *      Author: victor
 */

#pragma once

#include "engine/engine.h"
#include "server/zone/objects/creature/CreatureObject.h"
#include "server/zone/objects/player/PlayerObject.h"
#include "server/chat/PersistentMessage.h"

class SendMailTask : public Task {
	ManagedReference<CreatureObject*> receiver;
	ManagedReference<PersistentMessage*> mail;
	UnicodeString senderName;
public:
	SendMailTask(CreatureObject* receiver, PersistentMessage* mail, const UnicodeString& sender);

	void run() final;
};
