/*
 * ChatQueryRoomResults.h
 *
 *  Created on: Oct 10, 2015
 *      Author: Anakis
 */

#pragma once

#include "engine/service/proto/BaseMessage.h"
#include "server/chat/room/ChatRoom.h"

class ChatQueryRoomResults : public BaseMessage {
public:

	ChatQueryRoomResults(ChatRoom* room, int requestID = 0);

	void fillPlayerList(ChatRoom* room);

	void fillInvitedList(ChatRoom* room);

	void fillModeratorList(ChatRoom* room);

	void fillBannedList(ChatRoom* room);

};
