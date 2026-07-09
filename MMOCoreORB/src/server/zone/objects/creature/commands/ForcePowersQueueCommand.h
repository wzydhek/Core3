/*
 * ForcePowersQueueCommand.h
 *
 *  Created on: 24/05/2010
 *      Author: Valkyra
 */

#pragma once

#include "CombatQueueCommand.h"

class ForcePowersQueueCommand : public CombatQueueCommand {
public:

	ForcePowersQueueCommand(const String& name, ZoneProcessServer* server);

	int doCombatAction(CreatureObject* creature, const uint64& target, const UnicodeString& arguments = "") const;

	int getFrsModifiedForceCost(CreatureObject* creature) const;

	float getCommandDuration(CreatureObject* object, const UnicodeString& arguments) const;

	virtual bool isJediCombatQueueCommand();

};
