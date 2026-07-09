/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "server/zone/packets/BaseLineMessage.h"
#include "server/zone/objects/installation/harvester/HarvesterObject.h"

class HarvesterObjectMessage6 : public BaseLineMessage {
public:
	HarvesterObjectMessage6(HarvesterObject* hino);
};
