/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "server/zone/packets/DeltaMessage.h"
#include "server/zone/objects/player/PlayerObject.h"

class PlayerObjectDeltaMessage9 : public DeltaMessage {
	PlayerObject* play;

public:
	PlayerObjectDeltaMessage9(PlayerObject* pl);

	void updateStomachFilling();

	void updateFoodFilling(int newVal);

	void updateDrinkFilling(int newVal);

	void setLanguageID(uint8 lid);

	void setExperimentationEnabled(bool experimenting);

	void setExperimentationPoints(int points);

	void setCraftingState(int state);

	void setClosestCraftingStation(uint64 oid);

	void setJediState(int state);

};
