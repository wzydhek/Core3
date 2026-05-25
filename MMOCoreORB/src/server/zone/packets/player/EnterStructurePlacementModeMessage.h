/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "engine/service/proto/BaseMessage.h"

class EnterStructurePlacementModeMessage : public BaseMessage {
public:
	EnterStructurePlacementModeMessage(uint64 deedid, String crcpath) : BaseMessage() {
		insertShort(0x03);
		insertInt(0xE8A54DC1);  // CRC

		insertLong(deedid); //Deed ID
		insertAscii(crcpath); //path to the object.
	}
};
