#include "LairAggroTask.h"

LairAggroTask::LairAggroTask(TangibleObject* lair, TangibleObject* attacker, LairObserver* lairObserver, bool allAgentsAttack) {
	weakLair = lair;
	weakObserver = lairObserver;
	weakAttacker = attacker;
	allAttack = allAgentsAttack;
}

void LairAggroTask::run() {
	ManagedReference<TangibleObject*> lair = weakLair.get();

	if (lair == nullptr) {
		return;
	}

	ManagedReference<LairObserver*> lairObserver = weakObserver.get();
	ManagedReference<TangibleObject*> attacker = weakAttacker.get();

	if (lairObserver == nullptr || attacker == nullptr) {
		return;
	}

	Locker locker(lair);

	lairObserver->doAggro(lair, attacker, allAttack);
}