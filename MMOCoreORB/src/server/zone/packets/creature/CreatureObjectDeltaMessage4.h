/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "server/zone/packets/DeltaMessage.h"
#include "server/zone/objects/creature/CreatureObject.h"

class CreatureObjectDeltaMessage4 : public DeltaMessage {
	CreatureObject* creo;

public:
	CreatureObjectDeltaMessage4(CreatureObject* cr);

	void updateAccelerationMultiplierBase();

	void updateAccelerationMultiplierMod();

	void updateSpeedMultiplierBase();

	void updateSpeedMultiplierMod();

	void updateListenToID(uint64 objectid);

	void updateRunSpeed();

	void updateSlopeModAngle();

	void updateSlopeModPercent();

	void updateTurnScale();

	void updateWalkSpeed();

	void updateWaterModPercent();

	void updateSpeedAndAccelerationMods(bool sendSelf = true);
};
