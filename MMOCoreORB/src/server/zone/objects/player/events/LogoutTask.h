/*
 				Copyright <SWGEmu>
		See file COPYING for copying conditions. */

/**
 * LogoutTask.h
 *
 *  Created: Sat Oct  8 09:18:00 EDT 2011
 *   Author: lordkator
 *
 *  Description: Task created by LogoutServerCommand to implement the /logout process
 */

#pragma once

#include "server/zone/packets/player/LogoutMessage.h"
#include "engine/engine.h"
#include "server/zone/objects/creature/CreatureObject.h"

class LogoutTask: public Task {
	ManagedReference<CreatureObject*> creature;
	int timeLeft;

public:
	LogoutTask(CreatureObject* cr);

	void cancelLogout();

	void run();
};
