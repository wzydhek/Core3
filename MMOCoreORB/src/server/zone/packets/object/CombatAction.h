/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "StandaloneObjectControllerMessage.h"
#include "server/zone/managers/combat/DefenderHitList.h"
#include "server/zone/objects/creature/CreatureObject.h"
#include "server/zone/objects/tangible/TangibleObject.h"

class CombatAction : public StandaloneObjectControllerMessage {
	int defenderSize;


public:
	// set the new posture of attacker and defender BEFORE constructing a CombatAction

	CombatAction(CreatureObject* attacker, TangibleObject* defender, uint32 animcrc, uint8 hit, uint8 trails, long weaponID = 0);

	CombatAction(CreatureObject* attacker, uint32 animcrc);

	CombatAction(CreatureObject* attacker, uint32 animcrc, long weaponID);


	CombatAction(TangibleObject* attacker, CreatureObject* defender, uint32 animcrc, uint8 hit, long wpnID = 0);


	CombatAction(CreatureObject* attacker, CreatureObject* defender, uint32 animcrc, uint8 hit, long wpnID);

	CombatAction(TangibleObject* attacker, SortedVector<DefenderHitList*> targetDefenders, uint32 animcrc, uint8 trails, long weaponID);

	void updateDefenderSize();

	void addDefender(CreatureObject* defender, uint8 hit);
};
