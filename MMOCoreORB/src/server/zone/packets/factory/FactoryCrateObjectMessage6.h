/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "server/zone/packets/BaseLineMessage.h"
#include "server/zone/objects/tangible/TangibleObject.h"

class FactoryCrateObjectMessage6 : public BaseLineMessage {
public:
	FactoryCrateObjectMessage6(TangibleObject* tano);
	
};
