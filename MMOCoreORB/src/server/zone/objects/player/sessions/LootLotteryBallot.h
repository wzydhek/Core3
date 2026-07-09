/*
 * LootLotteryBallot.h
 *
 *  Created on: March 19, 2015
 *      Author: Anakis
 */

#pragma once

#include "engine/engine.h"
#include "system/util/Vector.h"
#include "server/zone/objects/creature/CreatureObject.h"

class LootLotteryBallot : public Object {

protected:

	ManagedWeakReference<CreatureObject*> player;
	SortedVector<uint64> lootSelections;

public:

     LootLotteryBallot(CreatureObject* pl, Vector<uint64> selection);

     bool hasSelection(uint64 objectID);

     CreatureObject* getPlayer();

};
