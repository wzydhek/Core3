/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "QueueCommand.h"

class SetPlayerAppearanceCommand : public QueueCommand {
public:

	SetPlayerAppearanceCommand(const String& name, ZoneProcessServer* server);

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const;

	void sendSyntax(CreatureObject* creature) const;

};

