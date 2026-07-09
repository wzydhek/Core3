/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "server/zone/packets/DeltaMessage.h"
#include "server/zone/objects/installation/InstallationObject.h"

class InstallationObjectDeltaMessage7 : public DeltaMessage {
	InstallationObject* inso;

public:
	InstallationObjectDeltaMessage7(InstallationObject* ins);

	void updateExtractionRate(float rate);

	void setNoHopperUpdate();

	void updateOperating(bool state);

	void updateHopper();

	void updateHopperSize(float size);

	void updateActiveResourceSpawn(uint64 id);

};
