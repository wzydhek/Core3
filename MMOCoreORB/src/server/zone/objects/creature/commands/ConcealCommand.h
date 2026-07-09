/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "QueueCommand.h"
#include "server/zone/Zone.h"
#include "server/zone/objects/tangible/TangibleObject.h"


class ConcealCommand : public QueueCommand {
public:
	ConcealCommand(const String& name, ZoneProcessServer* server);

	void doAnimations(CreatureObject* creature, CreatureObject* targetPlayer) const;

	bool checkHostileInRange(Zone* zone, CreatureObject* player) const;

	ManagedReference<TangibleObject*> getCamoKit(Zone* zone, CreatureObject* player) const;

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const;
};

