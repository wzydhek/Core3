#include "ChatInstantMessageToCharacter.h"
#include "server/zone/objects/creature/CreatureObject.h"
#include "server/chat/ChatManager.h"

ChatInstantMessageToCharacter::ChatInstantMessageToCharacter(ZoneClientSession* client, ZoneProcessServer* server) : MessageCallback(client, server), sequence(0) {
}

void ChatInstantMessageToCharacter::parse(Message* pack) {
	pack->parseAscii(game);
	pack->parseAscii(galaxy);

	pack->parseAscii(name);

	pack->parseUnicode(message);

	pack->shiftOffset(4);

	sequence = pack->parseInt();
}

void ChatInstantMessageToCharacter::run() {
	ChatManager* chatManager = server->getChatManager();

	chatManager->handleChatInstantMessageToCharacter(this);
}

const String& ChatInstantMessageToCharacter::getName() const {
	return name;
}

const String& ChatInstantMessageToCharacter::getGalaxy() const {
	return galaxy;
}

const String& ChatInstantMessageToCharacter::getGame() const {
	return game;
}

const UnicodeString& ChatInstantMessageToCharacter::getMessage() const {
	return message;
}

int ChatInstantMessageToCharacter::getSequence() const {
	return sequence;
}