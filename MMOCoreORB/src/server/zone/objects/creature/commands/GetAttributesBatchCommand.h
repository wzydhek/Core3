/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "QueueCommand.h"
#include "server/zone/objects/scene/SceneObject.h"

class GetAttributesBatchCommand : public QueueCommand {
public:

	const int MAXIMUM_BATCH = 999;

	GetAttributesBatchCommand(const String& name, ZoneProcessServer* server);

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const;

	void sendEmptyAttributes(CreatureObject* creature, uint64 objid) const;

	void sendAttributes(CreatureObject* creature, SceneObject* object, int incr) const;
};

