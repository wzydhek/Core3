/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "server/zone/packets/tangible/TangibleObjectDeltaMessage3.h"
#include "server/zone/objects/installation/InstallationObject.h"

class InstallationObjectDeltaMessage3 : public TangibleObjectDeltaMessage3 {
	InstallationObject* inso;

public:
	InstallationObjectDeltaMessage3(InstallationObject* ins);

	void updateOperating(bool value);
};
