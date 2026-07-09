/*
 * MessageCallback.h
 *
 *  Created on: 21/07/2009
 *      Author: TheAnswer
 */

#pragma once

#include "engine/core/Task.h"
#include "engine/log/Logger.h"
#include "server/zone/ZoneClientSession.h"
#include "server/zone/ZoneProcessServer.h"

namespace server {
namespace zone {
namespace packets {

	class MessageCallback : public Task, public Logger {
	protected:
		Reference<ZoneClientSession*> client;

		ManagedReference<ZoneProcessServer*> server;

	public:
		MessageCallback(ZoneClientSession* client, ZoneProcessServer* server);

		virtual ~MessageCallback();

		virtual void parse(Message* message) = 0;

		bool parseMessage(Message* packet);

		ZoneClientSession* getClient() const;

		ZoneProcessServer* getServer() const;

	};

}
}
}

using namespace server::zone::packets;
