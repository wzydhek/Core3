/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "engine/service/proto/BaseMessage.h"

class ObjectControllerMessage : public BaseMessage {
public:
	ObjectControllerMessage(uint64 objid, uint32 header1, uint32 header2, bool comp = true);

};
