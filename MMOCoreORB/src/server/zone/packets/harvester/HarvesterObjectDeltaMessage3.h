/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "server/zone/packets/DeltaMessage.h"
#include "server/zone/objects/installation/harvester/HarvesterObject.h"

class HarvesterObjectDeltaMessage3 : public DeltaMessage {
	HarvesterObject* haro;
	
public:
	HarvesterObjectDeltaMessage3(HarvesterObject* ho);

	void updateDamage(uint32 value);
	
};
