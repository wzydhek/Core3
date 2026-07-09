/*
 * ClientCreateCharacterCallback.cpp
 *
 *  Created on: Sep 5, 2009
 *      Author: theanswer
 */

#include "ClientCreateCharacterCallback.h"
#include "server/zone/managers/player/PlayerManager.h"
#include "server/zone/ZoneProcessServer.h"
#include "server/zone/objects/player/Races.h"

ClientCreateCharacterCallback::ClientCreateCharacterCallback(ZoneClientSession* client, ZoneProcessServer* server) : MessageCallback(client, server), species(0), height(0), tutflag(0) {
	setCustomTaskQueue("slowQueue");
}

void ClientCreateCharacterCallback::parse(Message* message) {
	message->parseAscii(customization);
	message->parseUnicode(characterName);

	message->parseAscii(racefile);
	message->parseAscii(location);

	message->parseAscii(hairobj);
	message->parseAscii(haircust); //grab the hair cust data

	message->parseAscii(profession);

	message->shiftOffset(1); //move past some unknown byte

	height = message->parseFloat();

	if (height < 0.7 || height > 1.5)
		height = 1;


	message->parseUnicode(bio); //get the biography.

	tutflag = message->parseByte(); //tutorial bool.

	int raceID = Races::getRaceID(racefile);
	species = Races::getSpeciesID(raceID);
}

void ClientCreateCharacterCallback::run() {
	if (client->getAccountID() == 0) {
		client->error("character create attempt with account id 0");

		return;
	}

	// client->info("ClientCreateCharacterCallback::run()", true);

	PlayerManager* playerManager = server->getPlayerManager();
	bool success = playerManager->createPlayer(this);

	if (success) {
		client->info("success creating char");
	} else {
		client->info("failed to create char");
	}
}

void ClientCreateCharacterCallback::getRaceFile(String& file) const {
	file = racefile;
}

void ClientCreateCharacterCallback::getCustomizationString(String& customizationString) const {
	customizationString = customization;
}

void ClientCreateCharacterCallback::getLocation(String& location) const {
	location = ClientCreateCharacterCallback::location;
}

void ClientCreateCharacterCallback::getHairObject(String& hair) const {
	hair = hairobj;
}

void ClientCreateCharacterCallback::getHairCustomization(String& hairCustomization) const {
	hairCustomization = haircust;
}

void ClientCreateCharacterCallback::getSkill(String& profession) const {
	profession = this->profession;
}

float ClientCreateCharacterCallback::getHeight() const {
	return height;
}

void ClientCreateCharacterCallback::getBiography(UnicodeString& biography) const {
	biography = bio;
}

bool ClientCreateCharacterCallback::getTutorialFlag() const {
	if (tutflag)
		return true;
	else
		return false;
}

void ClientCreateCharacterCallback::getCharacterName(UnicodeString& name) const {
	name = characterName;
}

int ClientCreateCharacterCallback::getSpecies() const {
	return species;
}