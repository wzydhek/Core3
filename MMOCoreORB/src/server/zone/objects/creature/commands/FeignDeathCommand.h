/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "QueueCommand.h"

class FeignDeathCommand : public QueueCommand {
public:
	FeignDeathCommand(const String& name, ZoneProcessServer* server);

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const override;

	void handleBuff(SceneObject* creature, ManagedObject* object, int64 param) const override;
};

