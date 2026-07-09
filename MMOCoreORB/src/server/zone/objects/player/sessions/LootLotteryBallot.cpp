#include "LootLotteryBallot.h"

LootLotteryBallot::LootLotteryBallot(CreatureObject* pl, Vector<uint64> selection) {
	player = pl;
	selection.clone(lootSelections);
}

bool LootLotteryBallot::hasSelection(uint64 objectID) {
	return lootSelections.contains(objectID);
}

CreatureObject* LootLotteryBallot::getPlayer() {
	return player.get();
}