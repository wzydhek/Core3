/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "engine/engine.h"
#include "engine/service/proto/StandaloneBaseMessage.h"

class StandaloneObjectControllerMessage : public StandaloneBaseMessage {
public:
	StandaloneObjectControllerMessage(uint64 objid, uint32 header1, uint32 header2, bool comp = true) {

		insertShort(0x05);
		insertInt(0x80CE5E46); // CRC
		insertInt(header1);
		insertInt(header2);
		insertLong(objid);
		insertInt(0x00);

		setCompression(comp);

	}
};
