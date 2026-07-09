/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "CombatQueueCommand.h"
#include "server/zone/objects/tangible/weapon/WeaponObject.h"

class ThrowGrenadeCommand : public CombatQueueCommand {
public:
	ThrowGrenadeCommand(const String& name, ZoneProcessServer* server);

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const;

	String getAnimation(TangibleObject* attacker, TangibleObject* defender, WeaponObject* weapon, uint8 hitLocation, int damage) const;

	float getCommandDuration(CreatureObject* object, const UnicodeString& arguments) const;
};
