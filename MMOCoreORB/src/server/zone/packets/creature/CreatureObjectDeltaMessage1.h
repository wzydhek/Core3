/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "server/zone/packets/DeltaMessage.h"

class CreatureObjectDeltaMessage1 : public DeltaMessage {
	CreatureObjectImplementation* creo;

public:
	CreatureObjectDeltaMessage1(CreatureObjectImplementation* cr)
			: DeltaMessage(cr->getObjectID(), 0x4352454F, 1) {
		creo = cr;
	}

	void updateBankCredits() {
		startUpdate(0x00);
		insertInt(creo->getBankCredits());
	}

	void updateCashCredits() {
		startUpdate(0x01);
		insertInt(creo->getCashCredits());
	}

};
