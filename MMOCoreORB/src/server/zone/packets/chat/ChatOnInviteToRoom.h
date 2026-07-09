/*
 * ChatOnInviteToRoom.h
 *
 *  Created on: Feb 12, 2016
 *      Author: Anakis
 */

#pragma once

#include "engine/service/proto/BaseMessage.h"
#include "server/zone/objects/creature/CreatureObject.h"

class ChatOnInviteToRoom : public BaseMessage {
public:
	ChatOnInviteToRoom(CreatureObject* inviter, const String& invitee, const String& roomPath, int error, int requestID);

};
