/*
 * ChatOnUnbanFromRoom.h
 *
 *  Created on: Feb 19, 2016
 *      Author: Anakis
 */

#pragma once

#include "engine/service/proto/BaseMessage.h"
#include "server/zone/objects/creature/CreatureObject.h"

class ChatOnUnbanFromRoom : public BaseMessage {
public:
	ChatOnUnbanFromRoom(CreatureObject* unbanner, const String& unbaneeName, const String& roomPath, int error, int requestID = 0);

};
