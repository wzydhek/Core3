/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "JediCombatQueueCommand.h"
#include "server/zone/objects/tangible/weapon/WeaponObject.h"

class SaberSlash1Command : public JediCombatQueueCommand {
public:

	SaberSlash1Command(const String& name, ZoneProcessServer* server);

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const;

	String getAnimation(TangibleObject* attacker, TangibleObject* defender, WeaponObject* weapon, uint8 hitLocation, int damage) const;

};
