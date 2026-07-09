/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "server/zone/packets/tangible/TangibleObjectMessage3.h"
#include "server/zone/objects/installation/InstallationObject.h"

class InstallationObjectMessage3 : public TangibleObjectMessage3 {
public:
	InstallationObjectMessage3(InstallationObject* inso);
};
