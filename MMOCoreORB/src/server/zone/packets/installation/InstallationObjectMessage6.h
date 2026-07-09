/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "server/zone/packets/tangible/TangibleObjectMessage6.h"
#include "server/zone/objects/installation/InstallationObject.h"

class InstallationObjectMessage6 : public TangibleObjectMessage6 {
public:
	InstallationObjectMessage6(InstallationObject* inso);
};
