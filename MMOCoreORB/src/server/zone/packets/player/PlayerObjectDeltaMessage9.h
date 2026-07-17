/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "server/zone/packets/DeltaMessage.h"
#include "server/zone/objects/player/PlayerObject.h"

namespace server {
namespace zone {
namespace packets {
namespace player {

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

} // namespace player
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::player;
