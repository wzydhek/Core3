/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "QueueCommand.h"
#include "server/zone/objects/scene/SceneObject.h"

class DismountCommand : public QueueCommand {
	Vector<uint32> restrictedBuffCRCs;
	uint32 gallopCRC;

public:
	DismountCommand(const String& name, ZoneProcessServer* server);

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const;

	void handleMount(CreatureObject* creature, SceneObject* mount) const;

	void removeMountBuffs(CreatureObject* vehicle) const;
};

