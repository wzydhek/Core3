/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "engine/engine.h"

namespace server {
namespace ping {

class PingClient : public BaseClientProxy {
public:
	PingClient(DatagramServiceThread* serv, Socket* sock, SocketAddress& addr);

	virtual ~PingClient();

	void disconnect(bool doLock = true);

	void sendMessage(Message* msg);
};

} // namespace ping
} // namespace server

using namespace server::ping;
