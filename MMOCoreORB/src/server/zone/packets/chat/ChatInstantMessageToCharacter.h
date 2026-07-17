/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "server/zone/packets/MessageCallback.h"

namespace server {
namespace zone {
namespace packets {
namespace chat {

class ChatInstantMessageToCharacter : public MessageCallback {
	String game;
	String galaxy;
	String name;
	UnicodeString message;

	uint32 sequence;
public:
	ChatInstantMessageToCharacter(ZoneClientSession* client, ZoneProcessServer* server);

	void parse(Message* pack);
	
	void run();

	const String& getName() const;

	const String& getGalaxy() const;

	const String& getGame() const;

	const UnicodeString& getMessage() const;

	int getSequence() const;

};

} // namespace chat
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::chat;
