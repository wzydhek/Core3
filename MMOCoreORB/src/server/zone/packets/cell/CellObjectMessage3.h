/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "server/zone/packets/BaseLineMessage.h"

class CellObjectMessage3 : public BaseLineMessage {
public:
	CellObjectMessage3(uint64 coId, int cellNumber);
};
