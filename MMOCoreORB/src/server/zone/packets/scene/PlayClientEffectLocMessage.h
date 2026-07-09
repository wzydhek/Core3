/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "engine/service/proto/BaseMessage.h"

class PlayClientEffectLoc : public BaseMessage {
public:
	int listSize;

	PlayClientEffectLoc(const String& file, const String& zoneName, float x, float z, float y, uint64 cell = 0, int terrainDelta = 0, const String& label = "");
};
