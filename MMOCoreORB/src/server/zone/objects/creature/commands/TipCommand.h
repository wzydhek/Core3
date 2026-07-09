/*
 				Copyright <SWGEmu>
		See file COPYING for copying conditions. */

#pragma once

#include "QueueCommand.h"
class TipCommand: public QueueCommand {
private:

	int performTip(CreatureObject* player, CreatureObject* targetPlayer, int amount) const;

	int performBankTip(CreatureObject* player, CreatureObject* targetPlayer, int amount) const;

public:

	TipCommand(const String& name, ZoneProcessServer* server);

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const;

};

