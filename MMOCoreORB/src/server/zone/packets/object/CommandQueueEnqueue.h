/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "ObjectControllerMessage.h"
#include "server/zone/packets/MessageCallback.h"
#include "server/zone/objects/creature/CreatureObject.h"

class CommandQueueEnqueue : public ObjectControllerMessage {
public:
	CommandQueueEnqueue(CreatureObject* creo, uint32 actioncnt, uint32 actionCRC);

};

class CommandQueueEnqueueCallback : public MessageCallback {
	uint32 size;
	uint32 actionCount;
	uint32 actionCRC;
	uint64 targetID;

	UnicodeString arguments;

	const char* actionName;

	ObjectControllerMessageCallback* objectControllerMain;
public:
	CommandQueueEnqueueCallback(ObjectControllerMessageCallback* objectControllerCallback);

	void parse(Message* message);

	void run();

	const char* getTaskName();
};
