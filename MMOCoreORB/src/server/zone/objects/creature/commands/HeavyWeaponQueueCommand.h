/*
 * HeavyWeaponQueueCommand.h
 *
 *  Created on: 13/05/2012
 *      Author: chris.rush
 */

#pragma once

#include "CombatQueueCommand.h"

class HeavyWeaponQueueCommand : public CombatQueueCommand {
public:

	HeavyWeaponQueueCommand(const String& name, ZoneProcessServer* server);

	int doCombatAction(CreatureObject* creature, const uint64& target, const UnicodeString& arguments = "") const;

	float getCommandDuration(CreatureObject* object, const UnicodeString& arguments) const;

};
