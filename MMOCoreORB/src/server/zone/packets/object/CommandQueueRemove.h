/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "ObjectControllerMessage.h"
#include "server/zone/objects/creature/CreatureObject.h"
#include "ObjectControllerMessageCallback.h"

namespace server {
namespace zone {
namespace packets {
namespace object {

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

} // namespace object
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::object;
