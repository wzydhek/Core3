/*
 * CreatureRangedAttackCommand.h
 *
 *  Created on: Jan 13, 2013
 *      Author: root
 */

#pragma once

#include "CombatQueueCommand.h"

class CreatureRangedAttackCommand : public CombatQueueCommand {
public:

	CreatureRangedAttackCommand(const String& name, ZoneProcessServer* server);

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const;
};
