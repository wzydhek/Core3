/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "engine/engine.h"
#include "engine/service/proto/StandaloneBaseMessage.h"

class StandaloneObjectControllerMessage : public StandaloneBaseMessage {
public:
	StandaloneObjectControllerMessage(uint64 objid, uint32 header1, uint32 header2, bool comp = true);
};
