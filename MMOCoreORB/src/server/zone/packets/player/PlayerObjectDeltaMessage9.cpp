#include "PlayerObjectDeltaMessage9.h"

PlayerObjectDeltaMessage9::PlayerObjectDeltaMessage9(PlayerObject* pl) : DeltaMessage(pl->getObjectID(), 0x504C4159, 9) {
	play = pl;
}

void PlayerObjectDeltaMessage9::updateStomachFilling() {
	addIntUpdate(0x0A, play->getFoodFilling());
	addIntUpdate(0x0B, play->getFoodFillingMax());
	addIntUpdate(0x0C, play->getDrinkFilling());
	addIntUpdate(0x0D, play->getDrinkFillingMax());
}

void PlayerObjectDeltaMessage9::updateFoodFilling(int newVal) {
	addIntUpdate(0x0A, newVal);
}

void PlayerObjectDeltaMessage9::updateDrinkFilling(int newVal) {
	addIntUpdate(0x0C, newVal);
}

void PlayerObjectDeltaMessage9::setLanguageID(uint8 lid) {
	startUpdate(9);
	insertInt((uint32)lid);
}

void PlayerObjectDeltaMessage9::setExperimentationEnabled(bool experimenting) {
	startUpdate(1);
	if (experimenting) {
		insertInt(3); // 3 // 4
	} else {
		insertInt(1);
	}
}

void PlayerObjectDeltaMessage9::setExperimentationPoints(int points) {
	startUpdate(5);
	insertInt(points); // Number of experimentation points
}

void PlayerObjectDeltaMessage9::setCraftingState(int state) {
	startUpdate(2);
	insertInt(state);
}

void PlayerObjectDeltaMessage9::setClosestCraftingStation(uint64 oid) {
	startUpdate(3);
	insertLong(oid);
}

void PlayerObjectDeltaMessage9::setJediState(int state) {
	startUpdate(0x11);
	insertInt(state);
}
