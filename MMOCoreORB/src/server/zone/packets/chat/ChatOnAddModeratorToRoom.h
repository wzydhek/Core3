/*
 * ChatOnAddModeratorToRoom.h
 *
 *  Created on: Feb 16, 2016
 *      Author: Anakis
 */

#pragma once

#include "engine/service/proto/BaseMessage.h"
#include "server/zone/objects/creature/CreatureObject.h"

class ChatOnAddModeratorToRoom : public BaseMessage {
public:
	ChatOnAddModeratorToRoom(CreatureObject* oper, const String& opeeName, const String& roomPath, int error, int requestID = 0);

};
