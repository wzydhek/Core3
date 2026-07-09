/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "QueueCommand.h"
#include "ServerCommandFactory.h"

class ServerCommand : public QueueCommand {
	MethodFactory<String, CreatureObject*, uint64, const String&> methodFactory;

public:

	ServerCommand(const String& name, ZoneProcessServer* server);

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const;

};

