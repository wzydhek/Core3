/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "ForcePowersQueueCommand.h"

class ForceLightningCone1Command : public ForcePowersQueueCommand {
public:

	ForceLightningCone1Command(const String& name, ZoneProcessServer* server);

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const;

};
