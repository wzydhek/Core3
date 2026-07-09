/*
 * NewTicketActivityResponseMessage.h
 *
 *  Created on: Nov 25, 2008
 *      Author: swgemu
 */

#pragma once

#include "engine/service/proto/BaseMessage.h"
#include "../MessageCallback.h"

class NewTicketActivityResponseMessage : public BaseMessage {
public:
	NewTicketActivityResponseMessage(byte flag, uint32 ticketid);

};

class NewTicketActivityMessageCalback : public MessageCallback {
	int ticketID;
public:
	NewTicketActivityMessageCalback(ZoneClientSession* client, ZoneProcessServer* server);

	void parse(Message* message);

	void run();
};
