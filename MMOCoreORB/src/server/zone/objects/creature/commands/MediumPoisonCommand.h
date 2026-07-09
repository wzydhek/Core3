/*
 * MediumPoisonCommand.h
 *
 *  Created on: Oct 9, 2010
 *      Author: da
 */

#pragma once

#include "CombatQueueCommand.h"

class MediumPoisonCommand : public CombatQueueCommand {
public:

	MediumPoisonCommand(const String& name, ZoneProcessServer* server);

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const;

};
