/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "QueueCommand.h"

class HoloEmoteCommand : public QueueCommand {
public:

	HoloEmoteCommand(const String& name, ZoneProcessServer* server);

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const;

	void handleEmote(CreatureObject* player, String& arg) const;

	void handleHelp(CreatureObject* player) const;

	void handleDelete(CreatureObject* player) const;

	bool isValidArgument(const String& arg) const;

};

