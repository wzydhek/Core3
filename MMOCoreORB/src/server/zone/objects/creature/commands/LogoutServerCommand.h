/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

/*
 * LogoutServerCommand.h
 *
 *  Created on: Aug 26, 2011
 *      Author: da
 *  Updated on: Sat Oct  8 11:00:07 EDT 2011 by lordkator
 */

#pragma once

#include "QueueCommand.h"

class LogoutServerCommand : public QueueCommand {
public:

	LogoutServerCommand(const String& name, ZoneProcessServer* server);

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const;
};

