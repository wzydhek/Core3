/*
 * GuildMailTask.h
 *
 *  Created on: Jan 21, 2015
 *      Author: TheAnswer
 */

#pragma once

#include "engine/engine.h"
#include "server/zone/objects/guild/GuildObject.h"
#include "server/chat/StringIdChatParameter.h"

class GuildMailTask : public Task {
	ManagedReference<GuildObject*> guild;
	StringIdChatParameter body;
	String subject;

public:
	GuildMailTask(const String& subject, StringIdChatParameter& body, GuildObject* guild);

	void run();
};
