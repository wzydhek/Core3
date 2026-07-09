/*
 * ChatOnRemoveModeratorFromRoom.h
 *
 *  Created on: Feb 17, 2016
 *      Author: Anakis
 */

#pragma once

#include "engine/service/proto/BaseMessage.h"
#include "server/zone/objects/creature/CreatureObject.h"

class ChatOnRemoveModeratorFromRoom : public BaseMessage {
public:
	ChatOnRemoveModeratorFromRoom(CreatureObject* deoper, const String& deopee, const String& roomPath, int error, int requestID = 0);

};
