/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "engine/service/proto/BaseMessage.h"
#include "server/zone/objects/creature/CreatureObject.h"

class CmdStartScene : public BaseMessage {
public:
	CmdStartScene(CreatureObject* creo);

	static void parse(Packet* pack);
}; // Class Start Scene
