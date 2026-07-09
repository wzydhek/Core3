/*
 * ShutdownTask.h
 *
 *  Created on: 20/05/2012
 *      Author: victor
 */

#pragma once

#include "server/ServerCore.h"
#include "server/zone/ZoneServer.h"
#include "server/chat/ChatManager.h"

class ShutdownTask : public Task {
	int minutesRemaining;
	int shutdownFlags;;
	ManagedReference<ZoneServer*> zoneServer;
public:
	ShutdownTask(ZoneServer* srv, int minutes, int flags = 0);

	void run();
};
