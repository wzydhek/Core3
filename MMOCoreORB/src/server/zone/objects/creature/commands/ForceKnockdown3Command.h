/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "ForcePowersQueueCommand.h"

class ForceKnockdown3Command : public ForcePowersQueueCommand {
public:

	ForceKnockdown3Command(const String& name, ZoneProcessServer* server);

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const;

};
