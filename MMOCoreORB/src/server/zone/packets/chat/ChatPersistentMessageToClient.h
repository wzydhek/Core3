/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "engine/service/proto/BaseMessage.h"
#include "server/chat/StringIdChatParameterVector.h"
#include "server/chat/PersistentMessage.h"

class ChatPersistentMessageToClient : public BaseMessage {
	void insertParameters(PersistentMessage* mail);

public:
	ChatPersistentMessageToClient(const String& sender, uint32 mailid, uint8 type, const UnicodeString& subject, const UnicodeString& body, uint32 timestamp = 0, char status = 'N');

	ChatPersistentMessageToClient(const String& sender, uint32 mailid, uint8 type, const UnicodeString& subject, StringIdChatParameter& body, uint32 timestamp = 0, char status = 'N');

	ChatPersistentMessageToClient(PersistentMessage* mail, const String& serverName, bool sendBody);
};
