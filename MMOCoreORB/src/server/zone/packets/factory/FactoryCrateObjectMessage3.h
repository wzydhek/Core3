/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "server/zone/packets/BaseLineMessage.h"
#include "server/zone/objects/factorycrate/FactoryCrate.h"

class FactoryCrateObjectMessage3 : public BaseLineMessage {
public:
	FactoryCrateObjectMessage3(FactoryCrate* crate, uint32 objType = 0x46435954, uint16 opcnt = 0x0B);

};
