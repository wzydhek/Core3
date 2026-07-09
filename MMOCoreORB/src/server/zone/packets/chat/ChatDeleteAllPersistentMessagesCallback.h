#pragma once

#include "server/zone/packets/MessageCallback.h"

class ChatDeleteAllPersistentMessagesCallback : public MessageCallback {
	uint64 playerID;
	uint64 targetID;

public:
	ChatDeleteAllPersistentMessagesCallback(ZoneClientSession* client, ZoneProcessServer* server);

	void parse(Message* message);

	void run();

};
