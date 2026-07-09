/*
	Copyright <SWGEmu>
	See file COPYING for copying conditions.
*/

#pragma once

// #define WAYPOINT_DEBUG

#include "QueueCommand.h"
#include "conf/ConfigManager.h"

class WaypointCommand : public QueueCommand {
private:
	bool advancedWaypoints = ConfigManager::instance()->getBool("Core3.PlayerManager.AdvancedWaypoints", false);
	String advancedGroundUsage = "Usage: /waypoint X Y <name> or /waypoint <name> or /waypoint <zone> X Z Y";
	String advancedSpaceUsage = "Usage: /waypoint X Z Y <name> or /waypoint <name> or /waypoint <zone> X Z Y";
	String groundUsage = "Usage: /waypoint X Y";
	String spaceUsage = "Usage: /waypoint X Z Y";
	mutable bool isSpaceZone;

public:
	WaypointCommand(const String& name, ZoneProcessServer* server);

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const;

	bool checkHasMoreTokens(CreatureObject* creature, StringTokenizer* tokenizer, float* position) const;

	bool getValidPosition(CreatureObject* creature, StringTokenizer* tokenizer, float* position, String* requiredArg = nullptr) const;

	void sendSystemMessage(CreatureObject* creature) const;
};

