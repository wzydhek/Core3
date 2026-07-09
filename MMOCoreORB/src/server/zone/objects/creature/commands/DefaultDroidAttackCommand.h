/*
 * DefaultDroidAttackCommand.h
 *
 *  Created on: Jan 14, 2013
 *      Author: root
 */

#pragma once

#include "CombatQueueCommand.h"

class DefaultDroidAttackCommand : public CombatQueueCommand {
public:

	DefaultDroidAttackCommand(const String& name, ZoneProcessServer* server);

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const;

};
