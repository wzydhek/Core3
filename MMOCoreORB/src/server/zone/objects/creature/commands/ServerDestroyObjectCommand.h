/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "QueueCommand.h"

class ServerDestroyObjectCommand : public QueueCommand {
public:
	ServerDestroyObjectCommand(const String& name, ZoneProcessServer* server);

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const;

	void destroyObject(SceneObject* object, CreatureObject* creature) const;
};

