/*
 * ChatPersistentMessageToServerCallback.h
 *
 *  Created on: 13/03/2010
 *      Author: victor
 */

#pragma once

#include "server/zone/packets/MessageCallback.h"
#include "server/chat/StringIdChatParameterVector.h"
#include "server/chat/WaypointChatParameterVector.h"
#include "server/zone/objects/creature/CreatureObject.h"

class ChatPersistentMessageToServerCallback : public MessageCallback {
	UnicodeString header;
	UnicodeString body;
	String recipientName;
	uint32 sequence;

	StringIdChatParameterVector stringIdParameters;
	WaypointChatParameterVector waypointParameters;

public:
	ChatPersistentMessageToServerCallback(ZoneClientSession* client, ZoneProcessServer* server);

	void parse(Message* message);

	int sendMail(CreatureObject* player, const String& recipient);

	int sendMailToPlayer(CreatureObject* player, const String& recipientName);

	void run();

};
