/*
 * DefuseMineTask.h
 *
 * Created on: 2024-08-15
 * Author: Hakry
 */

#pragma once

#include "server/zone/objects/creature/CreatureObject.h"
#include "server/zone/objects/tangible/weapon/WeaponObject.h"
#include "server/zone/objects/installation/components/MinefieldAttackTask.h"

class DefuseMineTask : public Task {
	const static uint32 MAX_CHANCE = 1000;
	const static uint32 ROLL_CHANCE = 750;

	ManagedWeakReference<CreatureObject*> weakPlayer;
	ManagedWeakReference<WeaponObject*> weakWeapon;
	ManagedWeakReference<TangibleObject*> weakMinefield;

public:
	DefuseMineTask(CreatureObject* player, WeaponObject* weapon, TangibleObject* minefield);

	void run();
};
