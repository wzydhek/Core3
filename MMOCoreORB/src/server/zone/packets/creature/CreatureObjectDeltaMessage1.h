/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "server/zone/packets/DeltaMessage.h"
#include "server/zone/objects/creature/CreatureObject.h"

class CreatureObjectDeltaMessage1 : public DeltaMessage {
	CreatureObjectImplementation* creo;

public:
	CreatureObjectDeltaMessage1(CreatureObjectImplementation* cr);

	void updateBankCredits();

	void updateCashCredits();

};
