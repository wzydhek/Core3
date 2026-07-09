/*
 * ChatOnUninviteFromRoom.h
 *
 *  Created on: Feb 14, 2016 - Yes, pretty sad huh? SWGEmu is my lady!! Lol!
 *      Author: Anakis
 */

#pragma once

#include "engine/service/proto/BaseMessage.h"
#include "server/zone/objects/creature/CreatureObject.h"

class ChatOnUninviteFromRoom : public BaseMessage {
public:
	ChatOnUninviteFromRoom(CreatureObject* uninviter, const String& uninvitee, const String& roomPath, int error, int requestID);

};
