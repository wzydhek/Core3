/*
 * CreateTicketMessageCallback.h
 *
 *  Created on: Nov 22, 2010
 *      Author: crush
 */

#pragma once

#include "server/zone/packets/MessageCallback.h"

class CreateTicketMessageCallback : public MessageCallback {
	String playerName;
	uint32 categoryId;
	uint32 subCategoryId;

	UnicodeString ticketBody;

public:
	CreateTicketMessageCallback(ZoneClientSession* client, ZoneProcessServer* server);

	void parse(Message* message);

	void run();
};
