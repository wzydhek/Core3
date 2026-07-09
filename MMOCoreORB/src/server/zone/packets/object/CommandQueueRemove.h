/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "ObjectControllerMessage.h"
#include "server/zone/objects/creature/CreatureObject.h"
#include "ObjectControllerMessageCallback.h"

class CommandQueueRemove : public ObjectControllerMessage {
public:
	CommandQueueRemove(CreatureObject* creo, uint32 actioncnt, float timer, uint32 tab1, uint32 tab2);

};

class CommandQueueRemoveCallback : public MessageCallback {
	uint32 size;
	uint32 actionCount;
	uint32 actionCRC;

	ObjectControllerMessageCallback* objectControllerMain;

public:

	CommandQueueRemoveCallback(ObjectControllerMessageCallback* objectControllerCallback);

	void parse(Message* message);

	void run();

};
