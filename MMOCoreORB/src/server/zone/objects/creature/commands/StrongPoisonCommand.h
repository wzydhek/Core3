/*
 * StrongPoisonCommand.h
 *
 *  Created on: Oct 9, 2010
 *      Author: da
 */

#pragma once

#include "CombatQueueCommand.h"

class StrongPoisonCommand : public CombatQueueCommand {
public:

	StrongPoisonCommand(const String& name, ZoneProcessServer* server);

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const;

};
