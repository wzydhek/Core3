/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/


#pragma once

#include "engine/service/proto/BaseMessage.h"

class ResourceHarvesterActivatePageMessage : public BaseMessage {
public:
	ResourceHarvesterActivatePageMessage(uint64 oid) : BaseMessage() {
    	insertShort(0x02);
    	insertInt(0xBD18C679);  // CRC
    	insertLong(oid);
	}

};
