/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "engine/service/proto/BaseMessage.h"

class CmdSceneReady : public BaseMessage {
public:
	CmdSceneReady();

	static void parse(Packet* pack);

};
