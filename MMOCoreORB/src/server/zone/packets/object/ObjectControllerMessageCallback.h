/*
 * ObjectControllerMessageCallback.h
 *
 *  Created on: Sep 6, 2009
 *      Author: theanswer
 */

#pragma once

#include "server/zone/MessageCallbackFactory.h"
#include "server/zone/packets/MessageCallback.h"

namespace server {
namespace zone {
namespace packets {
namespace object {

class ObjectControllerMessageCallback : public MessageCallback {
	uint32 priority;
	uint32 type;

	uint64 objectID;

	Reference<MessageCallback*> objectControllerCallback;
public:
	ObjectControllerMessageCallback(ZoneClientSession* client, ZoneProcessServer* server);

	static UniqueReference<MessageCallbackFactory<MessageCallback* (ObjectControllerMessageCallback*), uint32>*> objectMessageControllerFactory;

	const char* getTaskName();

	void parse(Message* message);

	void run();

	uint32 getPriority() const;

	uint32 getType() const;

	uint64 getObjectID() const;

};

} // namespace object
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::object;
