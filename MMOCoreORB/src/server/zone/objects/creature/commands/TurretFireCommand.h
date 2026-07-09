/*
 * TurretFireCommand.h
 *
 *  Created on: Dec 21, 2012
 *      Author: root
 */

#pragma once

#include "CombatQueueCommand.h"

class TurretFireCommand : public CombatQueueCommand {
public:
	TurretFireCommand(const String& name, ZoneProcessServer* server);

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const;
};
