/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "SpaceQueueCommand.h"
#include "server/zone/objects/ship/ShipObject.h"

class DockCommand : public SpaceQueueCommand {
private:
	constexpr static float DOCKING_RANGE = 200.f;

public:
	DockCommand(const String& name, ZoneProcessServer* server);

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const;

private:
	bool getDockingPermission(ShipObject* ship, ShipObject* target) const;

	void setDocking(ShipObject* ship, ShipObject* target) const;
};
