/*
 * LairAggroTask.h
 *
 * Created on: Jul 6, 2013
 * Author: swgemu
 */

#pragma once

#include "server/zone/managers/creature/LairObserver.h"
#include "server/zone/objects/tangible/TangibleObject.h"

namespace server {
namespace zone {
namespace managers {
namespace creature {

class LairAggroTask : public Task {
	ManagedWeakReference<TangibleObject*> weakLair;
	ManagedWeakReference<LairObserver*> weakObserver;
	ManagedWeakReference<TangibleObject*> weakAttacker;
	bool allAttack;

public:
	LairAggroTask(TangibleObject* lair, TangibleObject* attacker, LairObserver* lairObserver, bool allAgentsAttack);

	void run();
};

} // namespace creature
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::creature;
