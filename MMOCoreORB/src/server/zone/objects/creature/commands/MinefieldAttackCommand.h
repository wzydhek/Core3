/*
 * MinefieldAttackCommand.h
 *
 *  Created on: Dec 21, 2012
 *      Author: root
 */

#pragma once

#include "CombatQueueCommand.h"

class MinefieldAttackCommand : public CombatQueueCommand {
public:

	MinefieldAttackCommand(const String& name, ZoneProcessServer* server);

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const;

};
