/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "CombatQueueCommand.h"

class FireHeavyWeaponCommand : public CombatQueueCommand {
public:

	FireHeavyWeaponCommand(const String& name, ZoneProcessServer* server);

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const;

	String getAnimation(TangibleObject* attacker, TangibleObject* defender, WeaponObject* weapon, uint8 hitLocation, int damage) const;

	float getCommandDuration(CreatureObject* object, const UnicodeString& arguments) const;

};
