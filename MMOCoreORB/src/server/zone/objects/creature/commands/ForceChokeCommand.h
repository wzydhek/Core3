/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "ForcePowersQueueCommand.h"

class ForceChokeCommand : public ForcePowersQueueCommand {
public:

	ForceChokeCommand(const String& name, ZoneProcessServer* server);

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const;

};
