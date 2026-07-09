/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "engine/service/proto/BaseMessage.h"

class PlayMusicMessage : public BaseMessage {
public:

    PlayMusicMessage(const String& soundFile, uint64 target = 0, int unkInt = 1, bool unkBool = false);
	
};
