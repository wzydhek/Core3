/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "QueueCommand.h"
#include "server/zone/objects/waypoint/WaypointObject.h"

class GotoCommand : public QueueCommand {
public:
	GotoCommand(const String& name, ZoneProcessServer* server);

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const;

private:
	String getPlanetNameByCRC(uint32 planetCRC) const;

	float calculateWaypointManhattanDistance(CreatureObject* creature, WaypointObject* wp) const;
};

