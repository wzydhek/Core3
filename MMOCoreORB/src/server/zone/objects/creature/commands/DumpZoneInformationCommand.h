/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "QueueCommand.h"
#include "server/zone/objects/scene/SceneObject.h"
#include "server/zone/Zone.h"

class DumpZoneInformationCommand : public QueueCommand {
public:

	DumpZoneInformationCommand(const String& name, ZoneProcessServer* server);

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const;

	int dumpGroundZone(CreatureObject* creature, Zone* zone) const;

	int dumpSpaceZone(CreatureObject* creature, Zone* zone) const;
};

